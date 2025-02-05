/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:49:24 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/05 15:58:26 by rguigneb         ###   ########.fr       */
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
		philosopher->right_fork = create_fork();
		if (!philosopher->right_fork)
		{
			free_until_end(data->philosophers, 0, data->number_of_philo);
			return ;
		}
		if (i > 0)
			philosopher->left_fork = data->philosophers[i - 1]->right_fork;
		else if (i == data->number_of_philo - 1 && i != 0)
			data->philosophers[0]->left_fork = philosopher->right_fork;
	}
}
