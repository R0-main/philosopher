/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 15:39:38 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	check_for_limit(t_data *data)
{
	int				i;
	t_philosopher	*philo;

	if (!data || data->require_eat_count == -1)
		return ;
	i = -1;
	while (++i < data->number_of_philo)
	{
		philo = data->philosophers[i];
		if (philo->eat_count < data->require_eat_count)
			return ;
	}
	pthread_mutex_lock(&data->mutex);
	data->one_of_philo_died = true;
	pthread_mutex_unlock(&data->mutex);
}

void	handle_starvation(t_data *data, t_philosopher *philo)
{
	if (is_starving(philo))
	{
		pthread_mutex_lock(&data->mutex);
		data->one_of_philo_died = true;
		say(philo, "died of starvation 💀 !", "");
		exit(1);
		pthread_mutex_unlock(&data->mutex);
	}
}

void	*main_waiter_loop(void *ptr)
{
	t_data	*data;
	int		i;

	data = (t_data *)ptr;
	if (!data)
		return (NULL);
	i = 0;
	while (!data->one_of_philo_died)
	{
		handle_starvation(data, data->philosophers[i % data->number_of_philo]);
		i++;
		check_for_limit(data);
	}
	return (NULL);
}

void	create_waiter_thread(t_data *data)
{
	pthread_create(&data->waiter.thread, NULL, main_waiter_loop, (void *)data);
}
