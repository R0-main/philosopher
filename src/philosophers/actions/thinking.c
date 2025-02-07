/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 11:01:00 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	thinking_action(t_data *data, t_philosopher *philo)
{
	if (philo->action == THINK)
	{
		usleep(data->time_to_think * 1000);
		pthread_mutex_lock(&data->mutex);
		philo->action = EAT;
		pthread_mutex_unlock(&data->mutex);
		print_action(data, philo, false);
	}
}
