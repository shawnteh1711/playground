/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:57:34 by steh              #+#    #+#             */
/*   Updated: 2022/07/25 21:26:41 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parse.h"
#include "lexer.h"
#include "execute.h"

int	exec_cmd(t_shell *shell)
{
	//check if command is builtin 
		//if builtin; execve builtin
	// if (builtin(shell))
	// 	return (0);
	exec_disk_cmd(shell);
	// (void)shell;
	// char	*path = cmds[0].args[0];
	// char	*argv[] = {path, NULL};
	// char	*envp[] = {getenv("PATH"), NULL};
	// pid_t	pid = fork();
	// if (pid == -1)
	// 	err_exit("fork");
	// if (pid == 0)
	// {
		// execvp(cmds[0].args[0], cmds[0].args);
		// execve(cmds[0].args[0], cmds[0].args, envp);
		// need to get PATH from env
	// 	execve(cmds[0].args[0], argv, envp);
	// }
	// wait(NULL);
	return (0);
}

int	exec_disk_cmd(t_shell *shell)
{
	int	i;
	int	fd;
	int	fds[2];
	
	if (shell->cmd_count == 0)
		return (0);
	// if (*shell->infile != '\0')
	// {
	// 	cmds[0].infd = open(shell->infile, O_RDONLY);
	// }
	// if (*shell->outfile != '\0')
	// {
	// 	if (shell->append)
	// 		cmds[shell->cmd_count - 1].outfd = open(shell->outfile, O_WRONLY
	// 		| O_CREAT | O_APPEND, 0666);
	// 	else
	// 		cmds[shell->cmd_count - 1].outfd = open(shell->outfile, O_WRONLY
	// 		| O_CREAT | O_TRUNC, 0666);
	// }
	i = 0;
	if (*cmds[i].infile!= '\0')
	{
		cmds[0].infd = open(cmds[i].infile, O_RDONLY);
	}
	if (*cmds[i].outfile != '\0')
	{
		if (shell->append)
			cmds[shell->cmd_count - 1].outfd = open(cmds[i].outfile, O_WRONLY
			| O_CREAT | O_APPEND, 0666);
		else
			cmds[shell->cmd_count - 1].outfd = open(cmds[i].outfile, O_WRONLY
			| O_CREAT | O_TRUNC, 0666);
	}
	if (shell->heredoc == 1)
	{
		heredoc(shell);
	}
	while (i < shell->cmd_count)
	{
		if (i < shell->cmd_count - 1)
		{
			pipe(fds);
			cmds[i].outfd = fds[1];
			cmds[i + 1].infd = fds[0];
		}
		forkexec(shell, i);
		fd = cmds[i].infd;
		if (fd != 0)
		{
			close(fd);
		}
		fd = cmds[i].outfd;
		if (fd != 1)
		{
			close(fd);
		}
		++i;
	}
	while (wait(NULL) != shell->lastpid)
		;
	return (0);
}

void	forkexec(t_shell *shell, int i)
{
	pid_t	pid;
	// int		j;
	pid = fork();
	if (pid == -1)
		err_exit("fork");
	if (pid > 0)
	{
		shell->lastpid = pid;
	}
	else if (pid == 0)
	{
		if (cmds[i].infd != 0)
		{
			close(0);
			dup(cmds[i].infd);
		}
		if (cmds[i].outfd != 1)
		{
			close(1);
			dup(cmds[i].outfd);
		}
		// j = 3;
		// while (j < OPEN_MAX)
		// {
		// 	close(j);
		// 	++j;
		// }
		// signal(SIGINT, SIG_DFL);
		// signal(SIGQUIT, SIG_DFL);
		// char	*const envp[] = {getenv("PATH"), NULL};
		// char	*binaryPath = "/bin/";
		// char	*const argv[] = {binaryPath, cmds[i].args[0], NULL};
		// printf("envp: %s\n", *envp);
		// printf("cmds[i].args[0]: %s\n", cmds[i].args[0]);
		// printf("cmds[i].args: %s\n", *cmds[i].args);
		// if (execve(binaryPath, argv, NULL) == -1)
		// 	perror("execvp error");
		// system("leaks minishell");
		if (execvp(cmds[i].args[0], cmds[i].args) == -1)
			perror("execvp error\n");
		exit(EXIT_FAILURE);
	}
}
