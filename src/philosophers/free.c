/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:55:43 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 12:10:15 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philosopher.h"

void	free_until_end(t_philosopher **array, int i, int max)
{
	while (array[i] && i < max)
	{
		if (array[i]->right_fork)
		{
			pthread_mutex_destroy(&array[i]->right_fork->mutex);
			free(array[i]->right_fork);
		}
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_philosophers_array(t_data *data)
{
	free_until_end(data->philosophers, 0, data->number_of_philo);
}
