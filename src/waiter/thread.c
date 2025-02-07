/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 10:58:48 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	handle_starvation(t_data *data, t_philosopher *philo)
{
	if (is_starving(philo))
	{
		pthread_mutex_lock(&data->mutex);
		data->one_of_philo_died = true;
		pthread_mutex_unlock(&data->mutex);
		say(data, philo, "died of starvation 💀 !", "");
		exit(1);
	}
}

void	*main_waiter_loop(void *ptr)
{
	t_data	*data;
	int		i;
	int		d;

	data = (t_data *)ptr;
	if (!data)
		return (NULL);
	i = 0;
	while (!data->started)
		;
	while (!data->one_of_philo_died)
	{
		usleep(1000);
		handle_starvation(data, data->philosophers[i % data->number_of_philo]);
		pthread_mutex_lock(&data->mutex);
		if (data->philosophers[i
			% data->number_of_philo]->eat_count == data->require_eat_count)
			d++;
		if (d == data->number_of_philo)
			data->one_of_philo_died = true;
		pthread_mutex_unlock(&data->mutex);
		i++;
	}
	return (NULL);
}

void	create_waiter_thread(t_data *data)
{
	pthread_create(&data->waiter.thread, NULL, main_waiter_loop, (void *)data);
}
