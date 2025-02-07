/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:54:22 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 13:05:54 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "philosopher.h"
#include "garbadge.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void	*mythread(void *arg)
{
	int	*c;

	(void)arg;
	printf("Starting Thread Execution...\n");
	c = (int *)malloc(sizeof(4));
	*c = 4;
	printf("Finished Thread Execution...\n");
	return (c);
}

// int	main(void)
// {
// 	t_timer	timer;

// 	/* here, do your time-consuming job */
// 	timer.duration = 200; // ms
// 	start_timer(&timer);
// 	int i = 0;
// 	while (!is_timer_finished(&timer))
// 		i++;
// 	return (0);
// }

void	init_data(t_data *data)
{
	pthread_mutex_init(&data->mutex, NULL);
	data->one_of_philo_died = false;
	link_forks_with_philosophers(data);
	if (!data->philosophers)
		return ;
	data->waiter.queue = NULL;
	data->started = false;
	data->time_to_think = (data->time_to_die) - data->time_to_eat
		- data->time_to_sleep - 100;
	if (data->time_to_think < 0)
		data->time_to_think = 0;
	data->finished_eat = 0;
	create_philosophers_threads(data);
	create_waiter_thread(data);
	pthread_mutex_lock(&data->mutex);
	data->started = true;
	pthread_mutex_unlock(&data->mutex);
	pthread_join(data->waiter.thread, NULL);
}

int	main(int ac, char const **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (ac < 5 || ac > 6)
		return (ft_fprintf(STDERR_FILENO, HOW_TO_USE_ERROR), EXIT_FAILURE);
	if (!parse_arguments(&data, (char **)av))
		return (ft_fprintf(STDERR_FILENO, BAD_ARGUMENTS), EXIT_FAILURE);
	create_philosophers_array(&data);
	if (data.philosophers == NULL)
		return (ft_fprintf(STDERR_FILENO, MALLOC_FAILED_ON_PHILO_CREATION),
			EXIT_FAILURE);
	init_data(&data);
	if (!data.philosophers)
		return (ft_fprintf(STDERR_FILENO, MALLOC_FAILED_ON_PHILO_CREATION),
			EXIT_FAILURE);
	wait_for_all_threads(&data);
	pthread_mutex_destroy(&data.mutex);
	free_philosophers_array(&data);
	free_garbadge();
	return (EXIT_SUCCESS);
}
// free_forks_array(&data);
// create_forks_array(&data);
// if (data.forks == NULL)
// 	return (ft_fprintf(STDERR_FILENO, MALLOC_FAILED_ON_FORK_CREATION),
// 		EXIT_FAILURE);
