/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:00:05 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 10:21:56 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "philosopher.h"

static void	*main_threads_loop(void *ptr)
{
	t_philosopher	*philo;
	t_data			*data;

	philo = (t_philosopher *)ptr;
	if (!philo)
		return (NULL);
	data = philo->data;
	while (!r_bool(&data->mutex, &data->started))
		;
	while (1)
	{
		if (r_bool(&data->mutex, &data->one_of_philo_died))
			break ;
		pthread_mutex_lock(&philo->mutex);
		if (is_starving(philo))
			return (pthread_mutex_unlock(&philo->mutex), NULL);
		handle_actions(data, philo);
		if (is_starving(philo))
			return (pthread_mutex_unlock(&philo->mutex), NULL);
		pthread_mutex_unlock(&philo->mutex);
	}
	return (NULL);
}

void	create_philosophers_threads(t_data *data)
{
	int				i;

	i = -1;
	while (data->philosophers[++i])
	{
		pthread_create(&data->philosophers[i]->thread, NULL, main_threads_loop,
			(void *)data->philosophers[i]);
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
