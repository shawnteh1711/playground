/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:57:34 by steh              #+#    #+#             */
/*   Updated: 2022/06/24 22:18:27 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int parse(void)
{
	int	i;

	i = 0;
	t_builtin builtins[] = 
	{
		{"exit", do_exit},
		{NULL, NULL}
	};
	while (builtins[i].name != NULL)
	{
		if (builtins[i].name)
		{
			builtins[i].handler();
			break;
		}
	}
	return (0);
}

void	do_exit()
{
	printf("do_exit\n");
}
