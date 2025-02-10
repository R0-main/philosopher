/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:32:45 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 08:28:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	r_bool(t_data *data, bool *property)
{
	bool	r;

	pthread_mutex_lock(&data->mutex);
	r = *property;
	pthread_mutex_unlock(&data->mutex);
	return (r);
}

int	r_int(t_data *data, int *property)
{
	int	r;

	pthread_mutex_lock(&data->mutex);
	r = *property;
	pthread_mutex_unlock(&data->mutex);
	return (r);
}

t_philosopher	r_philosopher(t_data *data, t_philosopher property)
{
	t_philosopher	r;

	pthread_mutex_lock(&data->mutex);
	r = property;
	pthread_mutex_unlock(&data->mutex);
	return (r);
}
