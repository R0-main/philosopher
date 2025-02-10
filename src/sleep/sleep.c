/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:26:27 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 10:14:25 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	custom_usleep(t_data *data, t_philosopher *philo, long duration)
{
	t_timer	timer;

	timer.duration = duration;
	start_timer(&timer);
	(void)philo;
	(void)data;
	while (!is_timer_finished(&timer))
	{
		if (is_starving(philo))
			return (false);
		if (r_bool(&data->mutex, &data->one_of_philo_died))
			return (false);
		pthread_mutex_unlock(&philo->mutex);
		usleep(100);
		pthread_mutex_lock(&philo->mutex);
	}
	return (true);
}
