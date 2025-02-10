/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 11:26:25 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	lay_forks(t_data *data, t_philosopher *philo)
{
	lay_left_fork(data, philo);
	lay_right_fork(data, philo);
}

bool	eating_action(t_data *data, t_philosopher *philo)
{
	if (philo->action == EAT)
	{
		get_right_fork(data, philo);
		if (philo->left_fork)
		{
			get_left_fork(data, philo);
			if (is_starving(philo))
				return (lay_forks(data, philo), false);
			start_timer(&philo->starvation_timer);
			print_action(data, philo, THINK, false);
			trigger_action(data, philo, EAT);
			if (!custom_usleep(data, philo, data->time_to_eat))
				return (lay_forks(data, philo), false);
			lay_left_fork(data, philo);
			lay_right_fork(data, philo);
			philo->eat_count++;
			if (philo->eat_count == data->require_eat_count)
				data->finished_eat++;
			trigger_action(data, philo, SLEEP);
		}
		else if (!custom_usleep(data, philo, data->time_to_die + 10))
			return (false);
	}
	return (true);
}
