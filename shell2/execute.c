#include "execute.h"
#include "def.h"
#include "externs.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>

int	execute_disk_command(void)
{
	if (cmd_count == 0)
		return (0);
	if (infile[0] != '\0')
	{
		cmd[0].infd = open(infile, O_RDONLY);
	}
	
	if (outfile[0] != '\0')
	{
		if (append)
		{
			cmd[cmd_count - 1].outfd = open(outfile, O_WRONLY | O_CREAT
				| O_APPEND, 0666);
		}
		else
		{
			cmd[cmd_count - 1].outfd = open(outfile, O_WRONLY | O_CREAT
				| O_TRUNC, 0666);
		}
	}
	
	// When a child is terminated, 
	// a corresponding SIGCHLD signal is delivered to the parent, 
	// if we call the 'signal(SIGCHLD,SIG_IGN)', 
	// then the SIGCHLD signal is ignored by the system, 
	// and the child process entry is deleted from the process table. 
	// Thus, no zombie is created.
	if (backgnd == 1)
	{
		signal(SIGCHLD, SIG_IGN);
	}
	else
	{
		signal(SIGCHLD, SIG_DFL);
	}
	
	int	i;
	int	fd;
	int	fds[2];

	for (i = 0; i < cmd_count; ++i)
	{
		// if not last cmd, need to pipe
		if (i < cmd_count - 1)
		{
			pipe(fds);
			cmd[i].outfd = fds[1];
			cmd[i + 1].infd = fds[0];
		}

		forkexec(i);
		
		if ((fd = cmd[i].infd) != 0)
		{
			close(fd);
		}

		if ((fd = cmd[i].outfd) != 1)
		{
			close(fd);
		}
	}
	if (backgnd == 0)
	{
		while (wait(NULL) != lastpid)
		{
			;
		}
	}
	return (0);
}

void	forkexec(int i)
{
	pid_t	pid;
	pid = fork();

	if (pid == -1)
		ERR_EXIT("fork");
	
	if (pid > 0)
	{
		// parent process
		if (backgnd == 1)
		{
			printf("%d\n", pid);
		}
		
		lastpid = pid;
	}
	else if (pid == 0)
	{
		// child process

		// if background is 1, first cmd infd pass to /dev/null
		if (cmd[i].infd == 0 && backgnd == 1)
		{
			cmd[i].infd = open("/dev/null", O_RDONLY);
		}
		
		if (i == 0)
		{
			setpgid(0, 0);
		}
		
		if (cmd[i].infd != 0)
		{
			close(0);
			dup(cmd[i].infd);
		}
		if (cmd[i].outfd != 1)
		{
			close(1);
			dup(cmd[i].outfd);
		}

		int	j;
		for (j = 3; j < OPEN_MAX; ++j)
		{
			close(j);
		}

		// foreground process receive SIGINT, SIGQUIT
		// resume process
		if (backgnd == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
		}
		
		
		execvp(cmd[i].args[0], cmd[i].args);
		exit(EXIT_FAILURE);
	}
}