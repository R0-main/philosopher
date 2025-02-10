/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 10:47:40 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	handle_starvation(t_data *data, t_philosopher *philo)
{
	pthread_mutex_lock(&philo->mutex);
	if (is_starving(philo))
	{
		w_bool(&data->mutex, &data->one_of_philo_died, true);
		pthread_mutex_lock(&data->mutex);
		data->died_philo = philo;
		philo->can_talk = true;
		pthread_mutex_unlock(&data->mutex);
		pthread_mutex_unlock(&philo->mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->mutex);
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
	while (!r_bool(&data->mutex, &data->started))
		;
	while (1)
	{
		if (r_bool(&data->mutex, &data->one_of_philo_died))
			break ;
		usleep(100);
		philo = data->philosophers[i % data->number_of_philo];
		if (handle_starvation(data, philo))
			return (NULL);
		if (r_int(data, &data->finished_eat) == r_int(data,
				&data->number_of_philo))
			w_bool(&data->mutex, &data->one_of_philo_died, true);
		i++;
	}
	return (NULL);
}

void	create_waiter_thread(t_data *data)
{
	pthread_create(&data->waiter.thread, NULL, main_waiter_loop, (void *)data);
}
