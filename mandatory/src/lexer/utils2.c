/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:22:38 by steh              #+#    #+#             */
/*   Updated: 2022/07/15 16:40:05 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	assign_cmd2(int *i, int *j, int *inword, char *line)
{
	while (*line)
	{
		if (*line == ' ' || *line == '\t')
		{
			*inword = 0;
			break ;
		}
		else if (*line == '<' || *line == '>'
			|| *line == '|' || *line == '&'
			|| *line == '\n')
		{
			if (*inword == 0)
				cmds[*i].args[*j] = NULL;
			return (1);
		}
		else
			return (1);
	}
	return (0);
}
