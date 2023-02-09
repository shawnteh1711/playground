#include "parse.h"
#include "externs.h"
#include "init.h"
#include "execute.h"
#include "builtin.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>


void	get_command(int i);
void	getname(char *name);
void	print_command();

// main loop
void	shell_loop(void)
{
	while (1)
	{
		init();
		if (read_command() == -1)
			break;
		
		parse_command();
		print_command();
		execute_command();
	}
	printf("\nexit\n");
	

}

// return 0 if read success, return -1 if fail
int		read_command(void)
{
	if (fgets(cmdline, MAXLINE, stdin) == NULL)
		return (-1);
	return (0);
}


// return 0 if parse success, return -1 if fail
int		parse_command(void)
{
	// ls -l 
	// ls \0-l\0
	// char	*cp = cmdline;
	// char	*avp = avline;
	// int		i = 0;

	// while (*cp != '\0')
	// {
	// 	while (*cp == ' ' || *cp == '\t')
	// 	{
	// 		cp++ ;
	// 	}
	// 	if (*cp == '\0' || *cp == '\n')
	// 	{
	// 		break ;
	// 	}
	// 	cmd.args[i] = avp;
	// 	while (*cp != '\0'
	// 			&& *cp != ' '
	// 			&& *cp != '\t'
	// 			&& *cp != '\n')
	// 	{
	// 		*avp++ = *cp++;
	// 	}
	// 	*avp++ = '\0';
	// 	printf("[%s]\n", cmd.args[i]);
	// 	i++;
	// }

	if (check("\n"))
		return (0);

	if (builtin())
	{
		return (0);
	}
	// cat < test.txt | grep -n public > test2.txt &
	// 1. get first command
	get_command(0);
	// 2. check if < present
	if (check("<"))
	{
		getname(infile);
	}	
	// 3. check if | present
	int	i;
	for (i = 1; i < PIPELINE; ++i)
	{
		if (check("|"))
		{
			get_command(i);
		}
		else
		{
			break ;
		}
	}	
	// 4. check if > present
	if (check(">"))
	{
		if (check(">"))
		{
			append = 1;
		}
		getname(outfile);
	}
	// 5. check if & present
	if (check("&"))
	{
		backgnd = 1;
	}
	// 6. check if command line end '\n'
	if (check("\n"))
	{
		cmd_count = i;
		return (cmd_count);
	}
	else
	{
		fprintf(stderr, "Command line syntax error\n");
		return (-1);
	}
}

// return 0 if execute success, return -1 if fail
int		execute_command(void)
{
	// determine whether is builtin
	execute_disk_command();

	// pid_t	pid = fork();

	// if (pid == -1)
	// 	ERR_EXIT("fork");
	// if (pid == 0)
	// {
	// 	execvp(cmd.args[0], cmd.args);
	// }
	
	// wait(NULL);

	// ls | grep init | wc -w


	return (0);
}

// get all cmd[i]
// pass to avline 
// pass pointer to each cmd
void	get_command(int i)
{
	int	j = 0;
	int	inword;
	while (*lineptr != '\0')
	{
		// remove space
		while (*lineptr == ' ' || *lineptr == '\t')
			lineptr++;
		cmd[i].args[j] = avptr;
		while (*lineptr != '\0'
				&& *lineptr != ' '
				&& *lineptr != '\t'
				&& *lineptr != '>'
				&& *lineptr != '<'
				&& *lineptr != '|'
				&& *lineptr != '&'
				&& *lineptr != '\n')
		{
			*avptr++ = *lineptr++;
			inword = 1;
		}
		*avptr++ = '\0';
		switch (*lineptr)
		{
		case ' ':
		case '\t':
			inword = 0;
			j++;
			break;
		case '<':
		case '>':
		case '|':
		case '&':
		case '\n':
			if (inword == 0)
				cmd[i].args[j] = NULL;
			return ;
		default:
			return ;
		}
	}
}

int		check(char *str)
{
	char	*p;
	while (*lineptr == ' ' || *lineptr == '\t')
	{
		lineptr++;
	}
	p = lineptr;
	while (*str != '\0' && *str == *p)
	{
		str++;
		p++;
	}

	if (*str == '\0')
	{
		lineptr = p;
		return (1);
	}

	return (0);
}

void	getname(char *name)
{
	while (*lineptr == ' ' || *lineptr == '\t')
	{
		lineptr++;
	}

	while (*lineptr != '\0'
				&& *lineptr != ' '
				&& *lineptr != '\t'
				&& *lineptr != '>'
				&& *lineptr != '<'
				&& *lineptr != '|'
				&& *lineptr != '&'
				&& *lineptr != '\n')
		{
			*name++ = *lineptr++;
		}
		*name = '\0';
}

void	print_command()
{
	int	i;
	int	j;
	printf("cmd_count = %d\n", cmd_count);
	if (infile[0] != '\0')
	{
		printf("infile = [%s]\n", infile);
	}
	if (outfile[0] != '\0')
	{
		printf("outfile = [%s]\n", outfile);
	}

	for (i = 0; i < cmd_count; ++i)
	{
		j = 0;
		while (cmd[i].args[j] != NULL)
		{
			printf("[%s] ", cmd[i].args[j]);
			j++;
		}
		printf("\n");
	}
}
