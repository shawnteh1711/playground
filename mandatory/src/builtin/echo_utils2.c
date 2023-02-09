/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:23:44 by steh              #+#    #+#             */
/*   Updated: 2022/07/21 10:56:12 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"

char	*ft_crt_target(char *start, char **end, char *target, char *quotes)
{
	if (start != NULL)
	{
		start += ft_strlen(quotes);
		*end = ft_strstr(start, quotes);
		if (*end != NULL)
		{
			target = (char *)malloc(*end - start + 1);
			ft_memcpy(target, start, *end - start + 1);
			target[*end - start] = '\0';
		}
	}
	return (target);
}

char	*ft_split_quot(t_shell *shell, char **line, char *quotes)
{
	char	*start;
	char	*end;
	char	*target;
	char	*ret;

	end = NULL;
	target = NULL;
	start = ft_strstr(*line, quotes);
	target = ft_crt_target(start, &end, target, quotes);
	if (target == NULL)
	{
		printf("quotes not close\n");
		return (NULL);
	}
	if (target && ft_strcmp(quotes, "\'") == 0)
		printf("%s", target);
	else if (target && ft_strcmp(quotes, "\"") == 0)
	{
		if (target[0] == '$')
			target += ft_strlen("$");
		ret = ft_getenv(shell, target);
		if (ret == NULL)
			printf("%s", target);
		else
			printf("%s", ret);
	}
	free(target);
	return (end += 1);
}

// echo -nnn -nxxx $USER HELLO
char	*ck_nflag(char **line, int *j, int *nflag)
{
	*(line) += 1;
	while (**line)
	{
		if (**line == 'n')
			*(line) += 1;
		else
		{
			line = &cmds[0].args[*j];
			printf("%s ", *line);
			**line = '\0';
			return (*line);
		}
	}
	*nflag = 1;
	**line = '\0';
	return (*line);
}

void	ft_echo_print(char **c, int *j)
{
	if (c[*j + 1] == NULL)
		printf("%s", c[*j]);
	else
		printf("%s ", c[*j]);
}

void	ft_ck_echo(t_shell *shell, char **c, int *j, int *nflag)
{
	while (c[*j] != NULL)
	{
		if (*c[*j] == '-' && *(c[*j] + 1) == 'n')
			c[*j] = ck_nflag(c, j, nflag);
		else if (*c[*j] == '$')
		{
			c[*j] = ft_get_name(shell, &c[*j], "$");
			continue ;
		}
		else if (*c[*j] == '\"')
		{
			c[*j] = ft_split_quot(shell, &c[*j], "\"");
			continue ;
		}
		else if (*c[*j] == '\'')
		{
			c[*j] = ft_split_quot(shell, &c[*j], "\'");
			continue ;
		}
		else
			ft_echo_print(c, j);
		(*j)++;
	}
}
