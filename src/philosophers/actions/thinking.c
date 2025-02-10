/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 09:25:51 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	thinking_action(t_data *data, t_philosopher *philo)
{
	if (philo->action == THINK)
	{
		pthread_mutex_unlock(&philo->mutex);
		custom_usleep(data, philo, 1);
		pthread_mutex_lock(&philo->mutex);
		philo->action = EAT;
	}
}
