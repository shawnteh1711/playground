/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:01:46 by steh              #+#    #+#             */
/*   Updated: 2022/06/28 09:58:40 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parse.h"
# include <string.h>

int main(int argc, char const *argv[])
{
	char	*s;
	char	*a[1024];
	while (1)
	{
		s = readline("🧐minishell😋> ");
		add_history(s);
		// printf("lexer: [%s]\n", s);
		char	*token = strtok(s, " ");
		int	i = 0;
		while (token != NULL)
		{
			printf("token: %s\n", token);
			a[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		

		
	}
	
	
	
	return (0);
}

