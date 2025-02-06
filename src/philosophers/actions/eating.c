/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 14:18:12 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eating_action(t_data *data, t_philosopher *philo)
{
	if (philo->action == EAT && is_timer_finished(&philo->action_timer))
	{
		print_action(philo, false);
		if (philo->left_fork)
			philo->left_fork->used = false;
		if (philo->right_fork)
			philo->right_fork->used = false;
		philo->eat_count++;
		trigger_action(philo, SLEEP, data->time_to_sleep);
	}
}
