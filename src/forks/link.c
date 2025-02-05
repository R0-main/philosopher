/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:49:24 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/04 08:55:21 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	link_forks_with_philosophers(t_data *data)
{
	t_philosopher	*philosopher;
	int				i;

	i = -1;
	while (++i < data->number_of_philo)
	{
		philosopher = data->philosophers[i];
		philosopher->left_fork = data->forks[i % data->number_of_philo];
		philosopher->right_fork = data->forks[(i + 1) % data->number_of_philo];
	}
}
