/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 17:12:02 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eating_action(t_data *data, t_philosopher *philo)
{
	if (philo->action == EAT)
	{
		say(data, philo, "fqwfqfq", "");
		get_right_fork(data, philo);
		if (philo->left_fork)
		{
			get_left_fork(data, philo);
			start_timer(&philo->starvation_timer);
			philo->action = THINK;
			print_action(data, philo, false);
			trigger_action(data, philo, EAT, 1);
			pthread_mutex_unlock(&philo->mutex);
			custom_usleep(data, philo, data->time_to_eat * 1000);
			pthread_mutex_lock(&philo->mutex);
			lay_left_fork(data, philo);
			lay_right_fork(data, philo);
			philo->eat_count++;
			if (philo->eat_count == data->require_eat_count)
				data->finished_eat++;
			print_action(data, philo, false);
			trigger_action(data, philo, SLEEP, 1);
		}
		else
		{
			pthread_mutex_unlock(&philo->mutex);
			custom_usleep(data, philo, data->time_to_eat * 1000);
			pthread_mutex_lock(&philo->mutex);
		}
	}
}
