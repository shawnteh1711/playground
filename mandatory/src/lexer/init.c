/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:15:47 by steh              #+#    #+#             */
/*   Updated: 2022/07/26 11:47:46 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"
#include "builtin.h"

// ctlecho to remove ^c after press Ctrl + C
void	setup(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	disable_ctrl_c();
	disable_ctrl_d(false);
}

// Disable Ctrl+D
void	disable_ctrl_d(bool ig)
{
	struct termios	t;
	int				flag;

	flag = 0;
	tcgetattr(STDIN_FILENO, &t);
	if (ig)
		t.c_cc[VEOF] = 0;
	else
		t.c_cc[VEOF] = 4;
	tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

// prevent ^C from showing after press Ctrl+C
void	disable_ctrl_c(void)
{
	struct termios	t;

	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void	sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	init(t_shell *shell)
{
	int	i;

	ft_memset(cmds, 0, sizeof(cmds));
	ft_memset(shell->avline, 0, sizeof(shell->avline));
	// ft_memset(shell->infile, 0, sizeof(shell->infile));
	// ft_memset(shell->outfile, 0, sizeof(shell->outfile));
	shell->avptr = shell->avline;
	shell->lineptr = shell->cmdline;
	shell->append = 0;
	shell->heredoc = 0;
	shell->cmd_count = 0;
	shell->lastpid = 0;
	i = 0;
	while (i < PIPELINE)
	{
		cmds[i].infd = 0;
		cmds[i].outfd = 1;
		ft_memset(cmds[i].infile, 0, sizeof(cmds[i].infile));
		ft_memset(cmds[i].outfile, 0, sizeof(cmds[i].outfile));
		++i;
	}
}
