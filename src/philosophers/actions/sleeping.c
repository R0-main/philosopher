/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 09:12:48 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	sleeping_action(t_data *data, t_philosopher *philo)
{
	if (philo->action == SLEEP)
	{
		pthread_mutex_unlock(&philo->mutex);
		custom_usleep(data, philo, data->time_to_sleep);
		pthread_mutex_lock(&philo->mutex);
		trigger_action(data, philo, THINK);
	}
}
