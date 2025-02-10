/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:26:27 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 09:26:35 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	custom_usleep(t_data *data, t_philosopher *philo, long duration)
{
	t_timer	timer;

	timer.duration = duration;
	start_timer(&timer);
	(void)philo;
	(void)data;
	while (!is_timer_finished(&timer))
	{
		// if (r_bool(data, &data->one_of_philo_died))
		// 	return ;
		usleep(100);
	}
}
