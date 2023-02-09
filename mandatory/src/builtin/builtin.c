/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:16:52 by steh              #+#    #+#             */
/*   Updated: 2022/07/25 20:52:40 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parse.h"
#include "lexer.h"
#include "execute.h"

int	builtin(t_shell *shell)
{
	int					i;
	int					found;
	const t_builtin_cmd	builtins[] = {
	{"exit", do_exit}, {"cd", do_cd},
	{"pwd", do_pwd}, {"echo", do_echo},
	{"env", do_env}, {"export", do_export},
	{"unset", do_unset}, {NULL, NULL}};

	i = 0;
	found = 0;
	while (builtins[i].name != NULL)
	{
		if (check(shell, builtins[i].name))
		{
			builtins[i].handler(shell);
			found = 1;
			break ;
		}
		i++;
	}
	return (found);
}

void	do_exit(t_shell *shell)
{
	(void)shell;
	printf("exit\n");
	exit(EXIT_SUCCESS);
}

void	do_cd2(void)
{
	int		ret;
	char	cwd[LINE_MAX];
	int		i;

	i = 0;
	ft_memset(cwd, 0, sizeof(cwd));
	getcwd(cwd, sizeof(cwd));
	ret = ft_strcmp(cmds[0].args[0], "..");
	if (ret == 0)
	{
		chdir("..");
		getcwd(cwd, sizeof(cwd));
	}
	else if (chdir(cmds[0].args[0]) != 0)
		perror("chdir error");
	else
		chdir(cmds[0].args[0]);
}

// if cd .. return to two previous path, need to fix
// cd - go the the OLDPWD
void	do_cd(t_shell *shell)
{
	char	*tmp;
	char	*start;
	char	*end;
	char	*target;

	(void)shell;
	end = NULL;
	target = NULL;
	assign_cmd(shell);
	if (cmds[0].args[0] == NULL)
	{
		tmp = getenv("HOME");
		chdir(tmp);
	}
	else if (*cmds[0].args[0] == '\'')
	{
		start = ft_strstr(cmds[0].args[0], "\'");
		target = ft_crt_target(start, &end, target, "\'");
		chdir(target);
		free(target);
	}
	else
		do_cd2();
}

void	do_pwd(t_shell *shell)
{
	char	pwd[LINE_MAX];

	(void)shell;
	ft_memset(pwd, 0, sizeof(pwd));
	if (getcwd(pwd, sizeof(pwd)) == NULL)
		perror("getcwd error");
	else
		printf("%s\n", pwd);
}

void	do_echo(t_shell *shell)
{
	int			j;
	int			nflag;
	t_command	cmds_cp[PIPELINE];

	j = 0;
	nflag = 0;
	get_command(0, shell);
	// echo_cmd(shell);
	ft_memset(cmds_cp, 0, sizeof(cmds_cp));
	cmds_cp[0] = cmds[0];
	ft_ck_echo(shell, &cmds_cp[0].args[j], &j, &nflag);
	if (nflag == 0)
		printf("\n");
}
