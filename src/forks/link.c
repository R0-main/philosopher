/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:49:24 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 10:46:36 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	link_forks_with_philosophers(t_data *data)
{
	t_philosopher	*philosopher;
	int				i;

	i = 0;
	while (i < data->number_of_philo)
	{
		philosopher = data->philosophers[i];
		philosopher->right_fork = create_fork();
		if (!philosopher->right_fork)
		{
			free_until_end(data->philosophers, 0, data->number_of_philo);
			data->philosophers = NULL;
			return ;
		}
		philosopher->right_fork->mutex = \
			(pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		pthread_mutex_init(&philosopher->right_fork->mutex, NULL);
		if (i > 0)
			philosopher->left_fork = data->philosophers[i - 1]->right_fork;
		i++;
	}
	if (data->number_of_philo != 1)
		data->philosophers[0]->left_fork = \
			data->philosophers[data->number_of_philo - 1]->right_fork;
}
