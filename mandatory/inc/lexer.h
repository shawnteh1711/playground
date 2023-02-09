#ifndef LEXER_H
# define LEXER_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <termios.h>
#include <stdbool.h>
#include "../libft/libft.h"
#include "parse.h"

#define MAXARG 20
#define PIPELINE 5
#define MAXLINE 1024
#define MAXNAME 100

typedef	struct s_token t_token;

typedef	struct s_token
{
	char					*string; //echo
	int						type; //CMD
	t_token					*next;
}	t_token;

typedef	struct s_command
{
	char				*args[MAXARG + 1];
	char				*string;
	int					type;
	int					infd;
	int					outfd;
	char				infile[MAXNAME];
	char				outfile[MAXNAME];
	struct t_command	*next;
	t_token				*token;
}	t_command;

typedef	struct	s_shell
{
	char		avline[MAXLINE + 1];
	char		*cmdline;
	char		*avptr;
	char		*lineptr;
	int			append;
	int			heredoc;
	char		infile[MAXNAME];
	char		outfile[MAXNAME];
	int			cmd_count;
	int			lastpid;
	char		**envp;
	t_command	cmds[PIPELINE];
	// t_command	*head;
	// t_list		*head;
	size_t		env_size;
	t_list		*list;
}	t_shell;

typedef	struct s_coordinate
{
	int	i;
	int	j;
	int	k;
}	t_coordinate;


t_command	cmds[PIPELINE];

// initialize 
void	init(t_shell *shell);
void	setup(void);
void	shell_loop(t_shell *shell);
void	sigint_handler(int sig);
void 	disable_ctrl_d(bool ig);
void	disable_ctrl_c(void);

// read cmd
int		read_cmd(t_shell *shell);

// utils
void	err_exit(const char *msg);
void	print_command(t_shell *shell);
int		check(t_shell *shell, char *str);
void	getname(char *name, t_shell *shell);
void	assign_cmd(t_shell *shell);
int		assign_cmd2(int *i, int *j, int *inword, char *line);
int		check2(t_command *cmds, char *str);

// lexer
int		lexer_cmd(t_shell *shell);
char	**ft_lexer(char *s, int word);
int		ft_count_words(char *s);




#endif