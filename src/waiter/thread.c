/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:56 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 12:39:10 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	handle_eat_action(t_data *data, t_doubled_list **current)
{
	t_philosopher	*philo;

	(void)data;
	philo = (t_philosopher *)(*current)->content;
	if ((philo && philo->left_fork && philo->left_fork->used == false
			&& philo->right_fork && philo->right_fork->used == false
			&& (philo->can_ask_fork_timer.started
				&& is_timer_finished(&philo->can_ask_fork_timer)))
		|| (!philo->can_ask_fork_timer.started && philo->left_fork
			&& philo->left_fork->used == false && philo->right_fork
			&& philo->right_fork->used == false))
	{
		philo->left_fork->used = true;
		philo->right_fork->used = true;
		philo->asked_forks = false;
		trigger_action(philo, EAT, data->time_to_eat);
		philo->can_ask_fork_timer.duration = data->time_to_eat
			+ data->time_to_die / 4;
		start_timer(&philo->can_ask_fork_timer);
		ft_dlstremoveone(&data->waiter.queue, (*current));
		*current = data->waiter.queue;
		return ;
	}
	*current = (*current)->next;
}

static void	check_for_limit(t_data *data)
{
	int				i;
	t_philosopher	*philo;

	if (!data || data->require_eat_count == -1)
		return ;
	i = -1;
	while (++i < data->number_of_philo)
	{
		philo = data->philosophers[i];
		if (philo->eat_count < data->require_eat_count)
			return ;
	}
	data->one_of_philo_died = true;
}

void	*main_waiter_loop(void *ptr)
{
	t_data			*data;
	t_doubled_list	*current;
	t_doubled_list	*tmp;

	data = (t_data *)ptr;
	if (!data)
		return (NULL);
	while (!data->one_of_philo_died)
	{
		pthread_mutex_lock(&data->mutex);
		current = data->waiter.queue;
		// sort_queue_by_priority(data, current);
		while (current != NULL)
		{
			handle_eat_action(data, &current);
		}
		check_for_limit(data);
		pthread_mutex_unlock(&data->mutex);
	}
	pthread_mutex_lock(&data->mutex);
	current = data->waiter.queue;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	pthread_mutex_unlock(&data->mutex);
	return (NULL);
}

void	create_waiter_thread(t_data *data)
{
	pthread_create(&data->waiter.thread, NULL, main_waiter_loop, (void *)data);
}
