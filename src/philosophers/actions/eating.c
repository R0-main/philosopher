/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 14:17:51 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eating_action(t_data *data, t_philosopher *philo)
{
	if (philo->action == EAT)
	{
		get_right_fork(data, philo);
		if (philo->left_fork)
		{
			get_left_fork(data, philo);
			pthread_mutex_lock(&data->mutex);
			start_timer(&philo->starvation_timer);
			philo->action = THINK;
			pthread_mutex_unlock(&data->mutex);
			print_action(data, philo, false);
			pthread_mutex_lock(&data->mutex);
			philo->action = EAT;
			pthread_mutex_unlock(&data->mutex);
			print_action(data, philo, true);
			// pthread_mutex_unlock(&philo->mutex);
			usleep(data->time_to_eat * 1000);
			// pthread_mutex_lock(&philo->mutex);
			lay_left_fork(data, philo);
			lay_right_fork(data, philo);
			pthread_mutex_lock(&data->mutex);
			philo->eat_count++;
			if (philo->eat_count == data->require_eat_count)
				data->finished_eat++;
			pthread_mutex_unlock(&data->mutex);
			trigger_action(data, philo, SLEEP, 1);
			print_action(data, philo, false);
		}
	}
}
