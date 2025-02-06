/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:18:17 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 11:59:47 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static bool	is_lower_than(t_philosopher *philo, t_philosopher *prev_philo)
{
	if (!philo->eat_timer.started || date_lowest_than(philo->eat_timer.end_at,
			prev_philo->eat_timer.end_at))
		return (true);
	return (false);
}

static bool	is_sorted(t_doubled_list *lst)
{
	t_doubled_list	*current;
	t_philosopher	*philo;
	t_philosopher	*prev_philo;

	current = lst;
	while (current)
	{
		philo = (t_philosopher *)current->content;
		if (current->prev)
		{
			prev_philo = (t_philosopher *)current->prev->content;
			if (is_lower_than(philo, prev_philo))
				return (false);
		}
		current = current->next;
	}
	return (true);
}

void	sort_queue_by_priority(t_data *data, t_doubled_list *lst)
{
	t_doubled_list	*current;
	t_philosopher	*philo;
	t_philosopher	*prev_philo;
	t_doubled_list	*next;
	t_doubled_list	*prev;

	current = lst;
	(void)data;
	while (!is_sorted(lst))
	{
		philo = (t_philosopher *)current->content;
		if (current->prev)
		{
			prev_philo = (t_philosopher *)current->prev->content;
			if (is_lower_than(philo, prev_philo))
			{
				next = current->next;
				prev = current->prev;
				if (next)
				{
					next->prev = prev;
				}
				prev->next = next;
				if (prev->prev)
				{
					prev->prev->next = current;
				}
				else
					data->waiter.queue = current;
				current->prev = prev->prev;
				prev->prev = current;
				current->next = prev;
				continue ;
			}
		}
		current = current->next;
	}
}
