/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:00:05 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/05 15:40:41 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "philosopher.h"

static void	*main_threads_loop(void *ptr)
{
	t_thread_data	*data;
	t_philosopher	*philo;

	data = (t_thread_data *)ptr;
	if (!data)
		return (NULL);
	philo = data->philosopher;
	while (!data->data->one_of_philo_died)
	{
		pthread_mutex_lock(&data->data->mutex);
		if (philo->asked_forks == false)
		{
			say(philo, "asked for a fork!", "");
			ask_for_a_fork(data->data, philo);
		}
		else if (is_timer_finished(&philo->action_timer))
		{
			print_action(philo, false);
			philo->action_timer.duration = -1;
		}
		pthread_mutex_unlock(&data->data->mutex);
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
