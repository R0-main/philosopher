/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 14:20:37 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	handle_starvation(t_data *data, t_philosopher *philo)
{
	if (is_starving(philo))
	{
		data->one_of_philo_died = true;
		say(data, philo, "died of starvation 💀 !", "");
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
	while (!data->started)
		;
	while (!data->one_of_philo_died)
	{
		usleep(1000);
		philo = data->philosophers[i % data->number_of_philo];
		// pthread_mutex_lock(&philo->mutex);
		if (handle_starvation(data, philo))
			return (NULL);
		pthread_mutex_lock(&data->mutex);
		if (data->finished_eat == data->number_of_philo)
			data->one_of_philo_died = true;
		// pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&data->mutex);
		i++;
	}
	return (NULL);
}

void	create_waiter_thread(t_data *data)
{
	pthread_create(&data->waiter.thread, NULL, main_waiter_loop, (void *)data);
}
