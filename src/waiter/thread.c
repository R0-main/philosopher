/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 17:11:02 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	handle_starvation(t_data *data, t_philosopher *philo)
{
	if (is_starving(philo))
	{
		w_bool(&data->mutex, &data->one_of_philo_died, true);
		pthread_mutex_lock(&data->mutex);
		data->died_philo = philo;
		philo->can_talk = true;
		pthread_mutex_unlock(&data->mutex);
		return (true);
	}
	return (false);
}

void	*main_waiter_loop(void *ptr)
{
	t_data			*data;
	t_philosopher	*philo;
	int				i;

	data = (t_data *)ptr;
	if (!data)
		return (NULL);
	i = 0;
	while (!r_bool(data, &data->started))
		;
	while (!r_bool(data, &data->one_of_philo_died))
	{
		usleep(100);
		philo = data->philosophers[i % data->number_of_philo];
		pthread_mutex_lock(&philo->mutex);
		if (handle_starvation(data, philo))
			return (pthread_mutex_unlock(&philo->mutex), NULL);
		pthread_mutex_unlock(&philo->mutex);
		if (r_int(data, &data->finished_eat) == r_int(data,
				&data->number_of_philo))
		{
			w_bool(&data->mutex, &data->one_of_philo_died, true);
		}
		i++;
	}
	return (NULL);
}

void	create_waiter_thread(t_data *data)
{
	pthread_create(&data->waiter.thread, NULL, main_waiter_loop, (void *)data);
}
