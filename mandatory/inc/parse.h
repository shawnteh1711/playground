#ifndef PARSE_H
# define PARSE_H

#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef enum s_token_type
{
	CMD = 0,
	ARG = 1,
	RDR_INT = 2,
	HERE_DOC = 3,
	RDR_OUT = 4,
	APPEND = 5,
}	t_token_type;

int		parse_cmd(t_shell *shell);
int		parse_cmd2(t_shell *shell, int i);
void	get_command(int i, t_shell *shell);
int		get_command2(int *i, int *j, int *inword, char *line);

#endif