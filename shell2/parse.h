#ifndef _PARSE_H_
#define _PARSE_H_

void	shell_loop(void);
int		read_command(void);
int		parse_command(void);
int		execute_command(void);
void	print_command(void);
int		check(char *str);



#endif	/* _PARSE_H_ */