/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:25:08 by steh              #+#    #+#             */
/*   Updated: 2022/07/11 19:04:20 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"

int	heredoc(t_shell *shell)
{
	// char	**buf;
	char	*s;
	char 	*ret;
	
	// buf = NULL;
	// ft_memset(buf, 0, sizeof(buf));
	assign_cmd(shell);
	while (42)
	{
		s = readline("heredoc>");
		if (ft_strcmp(cmds[0].args[0], s) == 0)
			break ;
		ret = ft_strchr(s, '$');
		if (ret != NULL)
		{
			ret += 1;
			printf("%s\n", getenv(ret));
			return (1);
		}
	}
	return (0);
}