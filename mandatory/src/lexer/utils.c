/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:14:39 by steh              #+#    #+#             */
/*   Updated: 2022/07/25 21:27:43 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	err_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	print_command(t_shell *shell)
{
	int	i;
	int	j;

	printf("cmd_count = %d\n", shell->cmd_count);
	// if (*shell->infile != '\0')
	// {
	// 	printf("infile = [%s]\n", shell->infile);
	// }
	// if (*shell->outfile != '\0')
	// {
	// 	printf("outfile = [%s]\n", shell->outfile);
	// }
	i = 0;
	if (*cmds[i].infile != '\0')
	{
		printf("infile = [%s]\n", cmds[i].infile);
	}
	if (*cmds[i].outfile != '\0')
	{
		printf("outfile = [%s]\n", cmds[i].outfile);
	}
	while (i < shell->cmd_count)
	{
		j = 0;
		while (cmds[i].args[j] != NULL)
		{
			printf("[%s] ", cmds[i].args[j]);
			j++;
		}
		i++;
	}
	printf("\n");
}

int	check(t_shell *shell, char *str)
{
	char	*p;

	while (*shell->cmdline == ' ' || *shell->cmdline == '\t')
	{
		shell->cmdline++;
	}
	p = shell->cmdline;
	while (*str != '\0' && *str == *p)
	{
		str++;
		p++;
	}
	if (*str == '\0')
	{
		shell->cmdline = p;
		return (1);
	}
	return (0);
}

int	check2(t_command *cmds, char *str)
{
	if (ft_strcmp(cmds[0].args[0], str) == 0)
		return (1);
	return (0);
}

void	getname(char *name, t_shell *shell)
{
	while (*shell->cmdline == ' ' || *shell->cmdline == '\t')
	{
		shell->cmdline++;
	}
	while (*shell->cmdline != '\0' && *shell->cmdline != ' '
		&& *shell->cmdline != '\t' && *shell->cmdline != '>'
		&& *shell->cmdline != '<' && *shell->cmdline != '|'
		&& *shell->cmdline != '&' && *shell->cmdline != '\n')
	{
		*name++ = *shell->cmdline++;
	}
	*name++ = '\0';
}

void	assign_cmd(t_shell *shell)
{
	int		i;
	int		j;
	int		stat;
	int		inword;
	// char	*line;

	i = 0;
	j = 0;
	// line = shell->cmdline;
	while (*shell->cmdline != '\0')
	{
		while (*shell->cmdline == ' ' || *shell->cmdline == '\t')
			shell->cmdline++;
		cmds[i].args[j] = shell->avptr;
		while (*shell->cmdline != '\0' && *shell->cmdline != '\t' && *shell->cmdline != '>' && *shell->cmdline != '\"'
			&& *shell->cmdline != '<' && *shell->cmdline != '|' && *shell->cmdline != '&' && *shell->cmdline != '\n')
		{
			*shell->avptr++ = *shell->cmdline++;
			inword = 1;
		}
		*shell->avptr++ = '\0';
		stat = assign_cmd2(&i, &j, &inword, shell->cmdline);
		if (stat == 1)
			return ;
	}
}
