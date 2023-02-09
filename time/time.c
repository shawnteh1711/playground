/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:56:28 by steh              #+#    #+#             */
/*   Updated: 2022/06/11 22:23:51 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

long long	ft_t_stamp(long long msec)
{
	static long long	t_start = -1;
	
	if (t_start == -1)
	{	
		t_start = msec;
		return (0);
	}
	else
	{
		return (msec - t_start);
	}
}

long long	ft_cur_time(void)
{
	struct timeval		tv;
	time_t				sec;
	time_t				u_sec;
	long long			msec;

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec;
	u_sec = tv.tv_usec;
	msec = (sec * 1000) + (u_sec / 1000);
	return (ft_t_stamp(msec));
}


void	my_slp(long duration)
{
	long long	start;

	start = ft_cur_time();
	while (start <= duration)
	{
		usleep(50);
		start = ft_cur_time();
		printf("start: %llu\n", start);
	}
}




int	main(void)
{
	long long	msec;
	struct timeval	tv;

	msec = ft_cur_time();
	printf("msec: %llu\n", msec);
	my_slp(50);
}