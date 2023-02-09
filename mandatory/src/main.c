/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:01:46 by steh              #+#    #+#             */
/*   Updated: 2022/07/26 11:45:42 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"

int	main(int ac, char *av[], char *envp[])
{
	t_shell	shell;

	(void)ac;
	(void)av;
	shell.envp = envp;
	// malloc strict shell and command
	// shell(&shell)
	setup();
	shell_loop(&shell);
	return (0);
}
