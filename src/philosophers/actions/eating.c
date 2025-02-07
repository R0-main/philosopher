/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 11:13:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eating_action(t_data *data, t_philosopher *philo)
{
	if (philo->action == EAT)
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		say(data, philo, "has taken his right fork!", "");
		if (philo->left_fork)
		{
			pthread_mutex_lock(&philo->left_fork->mutex);
			say(data, philo, "has taken his left fork!", "");
			pthread_mutex_lock(&data->mutex);
			start_timer(&philo->starvation_timer);
			pthread_mutex_unlock(&data->mutex);
			print_action(data, philo, true);
			usleep(data->time_to_eat * 1000);
			pthread_mutex_unlock(&philo->left_fork->mutex);
			say(data, philo, "has put his left fork!", "");
			pthread_mutex_unlock(&philo->right_fork->mutex);
			say(data, philo, "has put his right fork!", "");
			pthread_mutex_lock(&data->mutex);
			philo->eat_count++;
			pthread_mutex_unlock(&data->mutex);
			trigger_action(data, philo, SLEEP, 1);
			print_action(data, philo, false);
		}
	}
}
