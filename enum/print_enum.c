/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_enum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:23:30 by steh              #+#    #+#             */
/*   Updated: 2022/06/11 22:25:19 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef enum s_stat
{
	EAT = 0,
	SLP = 1,
	THK = 2,
	DIE = 3
}	t_stat;

typedef	struct s_phil
{
	t_stat	stat;
}	t_phil;

const char* state(t_stat stat) 
{
	switch (stat) 
	{
		case EAT: return "Eat";
		case SLP: return "Slp";
		case THK: return "Thk";
		case DIE: return "Die";
		/* etc... */
	}
}

int	main(void)
{
	t_phil phil;

	phil.stat = SLP;
	printf("state: %s\n", state(phil.stat));

	return (0);
}
