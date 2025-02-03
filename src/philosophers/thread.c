/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:00:05 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/03 15:34:25 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "philosopher.h"

static void	*main_threads_loop(void *ptr)
{
	t_thread_data	*data;
	int				time;

	data = (t_thread_data *)ptr;
	(void)data;
	pthread_mutex_lock(&data->data->mutex);
	gettimeofday(&data->philosopher->last_action_date, NULL);
	time = (data->philosopher->last_action_date.tv_sec + 3600) % 86400;
	ft_fprintf(1, "Hey from %d ", data->philosopher->id);
	ft_fprintf(1, "at %d:%d:%d\n", time / 3600, (time % 3600) / 60, time % 60);
	pthread_mutex_unlock(&data->data->mutex);
	free(ptr);
	return (NULL);
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
	while (i < 1000000)
	{
		i++;
	}
	i = -1;
	while (data->philosophers[++i])
	{
		pthread_join(data->philosophers[i]->thread, NULL);
	}
}
