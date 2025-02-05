/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:38:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/05 14:30:51 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"
#include <stdio.h>

void	start_timer(t_timer *timer)
{
	int	usec;

	if (!timer || !timer->duration)
		return ;
	usec = ((timer->duration % 1000) * 1000) % 1000000;
	gettimeofday(&timer->started_at, 0);
	timer->end_at.tv_sec = timer->started_at.tv_sec + (timer->duration / 1000);
	if (usec + timer->started_at.tv_usec >= 1000000)
	{
		timer->end_at.tv_usec = (usec + timer->started_at.tv_usec) - 1000000;
		timer->end_at.tv_sec++;
	}
	else
		timer->end_at.tv_usec = timer->started_at.tv_usec + usec;
}

bool	is_timer_finished(t_timer *timer)
{
	t_time	time;

	if (!timer || !timer->duration)
		return (false);
	if (timer->duration == -1)
		return (false);
	gettimeofday(&time, 0);
	if (time.tv_sec > timer->end_at.tv_sec
		|| (time.tv_sec >= timer->end_at.tv_sec
			&& time.tv_usec >= timer->end_at.tv_usec))
		return (true);
	return (false);
}
