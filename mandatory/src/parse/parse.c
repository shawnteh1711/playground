/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:57:34 by steh              #+#    #+#             */
/*   Updated: 2022/07/26 12:21:05 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"

int	parse_cmd(t_shell *shell)
{
	int	i;
	int	stat;

	while (shell->cmdline)
	{
		if (builtin(shell))
			continue ;
		get_command(0, shell);
		if (check(shell, "<"))
		{
			if (check(shell, "<"))
				shell->heredoc = 1;
			else
				getname(shell->infile, shell);
		}
		i = 1;
		while (i < PIPELINE)
		{
			if (check(shell, "|"))
				get_command(i, shell);
			else
				break ;
			++i;
		}	
		stat = parse_cmd2(shell, i);
		if (stat)
			return (stat);
	}
	return (0);
}

int	parse_cmd2(t_shell *shell, int i)
{
	if (check(shell, ">"))
	{
		if (check(shell, ">"))
			shell->append = 1;
		getname(shell->outfile, shell);
	}
	if (check(shell, "\0"))
	{
		shell->cmd_count = i;
		return (shell->cmd_count);
	}
	else
	{
		printf("Command line syntax error\n");
		return (-1);
	}
}
