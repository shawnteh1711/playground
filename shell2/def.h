#ifndef _DEF_H_
#define _DEF_H_
#include <stdio.h>
#include <stdlib.h>

#define ERR_EXIT(m) \
	do				\
	{				\
		perror(m);	\
		exit(EXIT_FAILURE);	\
	}				\
	while (0)
#define MAXLINE 1024
#define MAXARG 20
#define PIPELINE 5
#define MAXNAME 100


typedef struct command
{
	char *args[MAXARG + 1];
	int	infd;
	int	outfd;
}	COMMAND;


#endif /* _DEF_H_ */