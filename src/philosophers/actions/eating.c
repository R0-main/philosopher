/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 10:25:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eating_action(t_data *data, t_philosopher *philo)
{
	if (philo->action == EAT)
	{
		pthread_mutex_lock(&data->mutex);
		say(philo, "asked for a fork!", "");
		pthread_mutex_unlock(&data->mutex);

		pthread_mutex_lock(&philo->left_fork->mutex);
		pthread_mutex_lock(&philo->right_fork->mutex);
		pthread_mutex_lock(&data->mutex);
		start_timer(&philo->starvation_timer);
		print_action(philo, true);
		pthread_mutex_unlock(&data->mutex);
		usleep(data->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);

		pthread_mutex_lock(&data->mutex);
		philo->eat_count++;
		print_action(philo, false);
		trigger_action(philo, SLEEP, 1);
		pthread_mutex_unlock(&data->mutex);

	}
}
