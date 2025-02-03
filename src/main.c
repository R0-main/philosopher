/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:54:22 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/03 13:40:33 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "philosopher.h"
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

int	main(int ac, char const **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (ft_fprintf(STDERR_FILENO, HOW_TO_USE_ERROR), EXIT_FAILURE);
	if (!parse_arguments(&data, (char **)av))
		return (ft_fprintf(STDERR_FILENO, BAD_ARGUMENTS), EXIT_FAILURE);
	create_philosophers_array(&data);
	if (data.philosophers == NULL)
		return (ft_fprintf(STDERR_FILENO, MALLOC_FAILED_ON_PHILO_CREATION),
			EXIT_FAILURE);
	create_forks_array(&data);
	if (data.forks == NULL)
		return (ft_fprintf(STDERR_FILENO, MALLOC_FAILED_ON_FORK_CREATION),
			EXIT_FAILURE);
	pthread_mutex_init(&data.mutex, NULL);
	create_philosophers_threads(&data);
	wait_for_all_threads(&data);
	free_philosophers_array(&data);
	free_forks_array(&data);
	return (EXIT_SUCCESS);
}
