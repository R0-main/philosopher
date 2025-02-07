/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 09:40:40 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	sleeping_action(t_data *data, t_philosopher *philo)
{
	if (philo->action == SLEEP)
	{
		usleep(data->time_to_sleep * 1000);
		pthread_mutex_lock(&data->mutex);
		print_action(philo, false);
		trigger_action(philo, THINK, 1);
		pthread_mutex_unlock(&data->mutex);
	}
}
