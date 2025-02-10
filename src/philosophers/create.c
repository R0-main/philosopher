/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:55:43 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 09:38:35 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philosopher.h"

t_philosopher	*create_philosopher(int id)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)malloc(sizeof(t_philosopher));
	if (!philo)
		return (NULL);
	ft_bzero(philo, sizeof(t_philosopher));
	philo->action = NONE;
	philo->id = id;
	philo->can_talk = true;
	return (philo);
}

void	create_philosophers_array(t_data *data)
{
	int					i;
	t_philosopher		**array;

	i = 0;
	data->philosophers = NULL;
	array = (t_philosopher **)malloc(sizeof(t_philosopher *)
			* (data->number_of_philo + 1));
	if (!array)
		return ;
	ft_bzero(array, sizeof(t_philosopher *) * (data->number_of_philo + 1));
	array[data->number_of_philo] = NULL;
	while (i < data->number_of_philo)
	{
		array[i] = create_philosopher(i);
		if (array[i] == NULL)
		{
			free_until_end(array, 0, data->number_of_philo);
			return ;
		}
		array[i]->data = data;
		array[i]->starvation_timer.duration = data->time_to_die;
		pthread_mutex_init(&array[i]->mutex, NULL);
		i++;
	}
	data->philosophers = array;
}
