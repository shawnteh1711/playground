/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:23:44 by steh              #+#    #+#             */
/*   Updated: 2022/07/21 11:24:26 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parse.h"
#include "lexer.h"
#include "execute.h"

char	*ck_cmd(t_shell *shell, char *line)
{
	while (*line != '\0' && *line != '\t' && *line != ' '
		&& *line != '>' && *line != '<' && *line != '|'
		&& *line != '&' && *line != '\n')
		*shell->avptr++ = *line++;
	return (line);
}

void	echo_cmd(t_shell *shell)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = shell->cmdline;
	while (*line != '\0')
	{
		while (*line == ' ' || *line == '\t')
			line++;
		cmds[i].args[j] = shell->avptr;
		line = ck_cmd(shell, line);
		*shell->avptr++ = '\0';
		echo_cmd2(&i, &j, line);
	}
}

void	echo_cmd2(int *i, int *j, char *line)
{
	while (*line)
	{
		if (*line == ' ' || *line == '\t')
		{
			(*j)++;
			break ;
		}
		else if (*line == '<' || *line == '>' || *line == '|'
			|| *line == '&' || *line == '\n')
		{
			cmds[*i].args[*j] = NULL;
			return ;
		}
		else
			return ;
	}
	return ;
}

char	*ft_get_name(t_shell *shell, char **line, char *quotes)
{
	char	*start;
	char	arr[10];
	char	*ret;
	int		i;

	i = 0;
	ft_memset(arr, 0, sizeof(arr));
	start = ft_strstr(*line, quotes);
	if (start != NULL)
	{
		start += ft_strlen("$");
		while (ft_isalpha(*start))
		{
			arr[i] = *start;
			i++;
			start++;
		}
		arr[i] = '\0';
		ret = ft_getenv(shell, arr);
		if (ret == NULL)
			return (start);
		printf("%s", ret);
	}
	return (start);
}
