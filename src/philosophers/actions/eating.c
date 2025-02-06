/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 15:40:25 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eating_action(t_data *data, t_philosopher *philo)
{
	if (philo->action == EAT && is_timer_finished(&philo->action_timer))
	{
		philo->starvation_timer.duration = data->time_to_die;
		start_timer(&philo->starvation_timer);
		pthread_mutex_lock(&philo->left_fork->mutex);
		pthread_mutex_lock(&philo->right_fork->mutex);
		philo->eat_count++;
		print_action(philo, true);
		usleep(data->time_to_eat * 1000);
		print_action(philo, false);
		trigger_action(philo, SLEEP, data->time_to_sleep);
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
	}
}
