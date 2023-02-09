/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:57:28 by steh              #+#    #+#             */
/*   Updated: 2022/07/23 20:35:45 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"

void	do_env(t_shell *shell)
{
	int		i;

	i = 0;
	while (shell->envp[i] != NULL)
	{
		printf("%s\n", shell->envp[i]);
		i++;
	}
	shell->env_size = i;
}

// if var name not in env, add new else update
// need to handle "hello world", have " ", need to include whole into variable
void	do_export(t_shell *shell)
{
	char	**arr;
	char	*var;
	char	*ret;
	int		i;

	i = 0;
	while (shell->envp[i] != NULL)
		i++;
	assign_cmd(shell);
	if (ft_strchr(cmds[0].args[0], '=') == NULL)
	{
		printf("export must be key=value\n");
		return ;
	}
	var = ft_strdup(cmds[0].args[0]);
	arr = ft_split(var, '=');
	ret = ft_getenv(shell, arr[0]);
	if (ret == NULL)
	{
		shell->envp[i] = var;
		shell->envp[++i] = NULL;
	}
	else
		ft_setenv(shell, arr[0], arr[1]);
	do_env(shell);
}

void	do_unset(t_shell *shell)
{
	char	**arr;
	char	*var;
	int		ret;

	assign_cmd(shell);
	var = ft_strdup(cmds[0].args[0]);
	arr = ft_split(var, '=');
	ret = ft_unsetenv(shell, arr[0]);
	if (ret == -1)
		perror("unset");
	do_env(shell);
}
