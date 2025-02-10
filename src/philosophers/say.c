/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   say.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:33:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 10:33:15 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	say(t_data *data, t_philosopher *philo, const char *str1,
		const char *str2)
{
	t_time	time;
	long	ms_since_begin;

	gettimeofday(&time, 0);
	ms_since_begin = ((time.tv_sec - data->start_time.tv_sec) * 1000)
		+ ((time.tv_usec - data->start_time.tv_usec) / 1000);
	pthread_mutex_lock(&data->mutex);
	if (!data->died_philo || data->died_philo == philo)
		ft_fprintf(STDOUT_FILENO, SAY_PRINT, ms_since_begin, philo->id, str1,
			str2);
	pthread_mutex_unlock(&data->mutex);
}
