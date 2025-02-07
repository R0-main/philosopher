/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:00:05 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 17:13:37 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "philosopher.h"

static void	*main_threads_loop(void *ptr)
{
	t_thread_data	*thread_data;
	t_data			*data;
	t_philosopher	*philo;

	thread_data = (t_thread_data *)ptr;
	if (!thread_data)
		return (NULL);
	data = thread_data->data;
	philo = thread_data->philosopher;
	while (!r_bool(data, &data->started))
		;
	while (!r_bool(data, &data->one_of_philo_died))
	{
		pthread_mutex_lock(&philo->mutex);
		if (is_starving(philo))
			return (pthread_mutex_unlock(&philo->mutex), free(ptr), NULL);
		handle_actions(data, philo);
		if (is_starving(philo))
			return (pthread_mutex_unlock(&philo->mutex), free(ptr), NULL);
		pthread_mutex_unlock(&philo->mutex);
	}
	return (free(ptr), NULL);
}

void	create_philosophers_threads(t_data *data)
{
	int				i;
	t_thread_data	*thread_data;

	i = -1;
	while (data->philosophers[++i])
	{
		thread_data = malloc(sizeof(t_thread_data));
		if (!thread_data)
			return ;
		thread_data->data = data;
		thread_data->philosopher = data->philosophers[i];
		pthread_create(&data->philosophers[i]->thread, NULL, main_threads_loop,
			(void *)thread_data);
	}
}

void	wait_for_all_threads(t_data *data)
{
	int	i;

	i = -1;
	while (data->philosophers[++i])
	{
		if (data->philosophers[i]->thread)
			pthread_join(data->philosophers[i]->thread, NULL);
	}
}
