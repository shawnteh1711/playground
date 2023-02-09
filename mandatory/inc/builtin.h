#ifndef BUILTIN_H
# define BUILTIN_H

#include "lexer.h"

typedef	void	(*cmd_handler)(t_shell *shell);
typedef	struct	s_builtin_cmd
{
	char		*name;
	cmd_handler	handler;
}	t_builtin_cmd;

int		builtin(t_shell *shell);
void	do_exit(t_shell *shell);
void	do_cd(t_shell *shell);
void	do_pwd(t_shell *shell);
void	do_echo(t_shell *shell);
void	do_env(t_shell *shell);
void	do_export(t_shell *shell);
void	do_unset(t_shell *shell);

//env utils
char	*ft_getenv(t_shell *shell, const char *name);
void	ft_setenv(t_shell *shell, const char *key, char *value);
int		ft_unsetenv(t_shell *shell, const char *name);

//echo utils
void	echo_cmd(t_shell *shell);
void	echo_cmd2(int *i, int *j, char *line);
char	*ck_cmd(t_shell *shell, char *line);

//echo utils2
char	*ft_split_quot(t_shell *shell, char **line, char *quotes);
char	*ft_get_name(t_shell *shell, char **line, char *quotes);
char	*ck_nflag(char **line, int *j, int *nflag);
void	ft_ck_echo(t_shell *shell, char **c, int *j, int *nflag);
char	*ft_crt_target(char *start, char **end, char *target, char *quotes);

#endif