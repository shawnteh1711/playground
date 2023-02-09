/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_backup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:07:54 by steh              #+#    #+#             */
/*   Updated: 2022/07/21 01:14:01 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parse.h"
#include "lexer.h"
#include "execute.h"

void	do_echo3(t_shell *shell)
{
	int			j;
	int			nflag;
	t_command	cmds_cp[PIPELINE];

	j = 0;
	nflag = 0;
	echo_cmd(shell);
	ft_memset(cmds_cp, 0, sizeof(cmds_cp));
	cmds_cp[0] = cmds[0];
	while (cmds_cp[0].args[j] != NULL)
	{
		if (*cmds_cp[0].args[j] == '-' && *(cmds_cp[0].args[j] + 1) == 'n')
			cmds_cp[0].args[j] = ck_nflag(&cmds_cp[0].args[j], &j, &nflag);
		else if (*cmds_cp[0].args[j] == '$')
		{
			cmds_cp[0].args[j] = ft_get_name(shell, &cmds_cp[0].args[j], "$");
			continue ;
		}
		else if (*cmds_cp[0].args[j] == '\"')
		{
			cmds_cp[0].args[j] = ft_split_quot(shell, &cmds_cp[0].args[j], "\"");
			continue ;
		}
		else if (*cmds_cp[0].args[j] == '\'')
		{
			cmds_cp[0].args[j] = ft_split_quot(shell, &cmds_cp[0].args[j], "\'");
			continue ;
		}
		else
		{
			if (cmds_cp[0].args[j + 1] == NULL)
				printf("%s", cmds_cp[0].args[j]);
			else
				printf("%s ", cmds_cp[0].args[j]);
		}
		j++;
	}
	if (nflag == 0)
		printf("\n");
}
