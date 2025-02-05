/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/05 15:45:31 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*main_waiter_loop(void *ptr)
{
	t_data			*data;
	t_philosopher	*philo;

	data = (t_data *)ptr;
	if (!data)
		return (NULL);
	while (!data->one_of_philo_died)
	{
		if (data->waiter.queue != NULL)
		{
			pthread_mutex_lock(&data->mutex);
			philo = (t_philosopher *)data->waiter.queue->content;
			if (philo->left_fork->used == false
				&& philo->right_fork->used == false)
			{
				philo->left_fork->used = true;
				philo->right_fork->used = true;
				trigger_action(philo, EAT, data->time_to_eat);
			}
			pthread_mutex_unlock(&data->mutex);
		}
	}
	return (NULL);
}

void	create_waiter_thread(t_data *data)
{
	pthread_create(&data->waiter.thread, NULL, main_waiter_loop, (void *)data);
}
