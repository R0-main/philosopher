/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 09:21:42 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	handle_eat_action(t_data *data, t_list **current, t_list **prev)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)(*current)->content;
	if (philo && philo->left_fork && philo->left_fork->used == false
		&& philo->right_fork && philo->right_fork->used == false)
	{
		philo->left_fork->used = true;
		philo->right_fork->used = true;
		philo->asked_forks = false;
		trigger_action(philo, EAT, data->time_to_eat);
		if ((*prev))
			(*prev)->next = (*current)->next;
		else
			data->waiter.queue = (*current)->next;
		free((*current));
		(*current) = (*prev);
	}
	(*prev) = (*current);
	if ((*current))
		(*current) = (*current)->next;
}

void	*main_waiter_loop(void *ptr)
{
	t_data	*data;
	t_list	*current;
	t_list	*prev;

	data = (t_data *)ptr;
	if (!data)
		return (NULL);
	while (!data->one_of_philo_died)
	{
		prev = NULL;
		current = data->waiter.queue;
		sort_queue_by_priority(current);
		while (current != NULL)
		{
			pthread_mutex_lock(&data->mutex);
			handle_eat_action(data, &current, &prev);
			pthread_mutex_unlock(&data->mutex);
		}
	}
	return (NULL);
}

void	create_waiter_thread(t_data *data)
{
	pthread_create(&data->waiter.thread, NULL, main_waiter_loop, (void *)data);
}
