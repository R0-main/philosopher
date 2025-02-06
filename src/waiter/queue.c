/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:18:17 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 09:38:18 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static bool	is_lower_than(t_philosopher *philo, t_philosopher *prev_philo)
{
	if (prev_philo->action != NONE || date_lowest_than(philo->eat_timer.end_at,
			prev_philo->eat_timer.end_at))
		return (true);
	return (false);
}

static bool	is_sorted(t_list *lst)
{
	t_list			*current;
	t_list			*prev;
	t_philosopher	*philo;
	t_philosopher	*prev_philo;

	prev = lst;
	current = lst;
	while (current)
	{
		philo = (t_philosopher *)current->content;
		prev_philo = (t_philosopher *)prev->content;
		if (is_lower_than(philo, prev_philo) && philo != prev_philo)
			return (false);
		prev = current;
		current = current->next;
	}
	return (true);
}

void	sort_queue_by_priority(t_list *lst)
{
	t_list			*current;
	t_list			*prev;
	t_philosopher	*philo;
	t_philosopher	*prev_philo;

	prev = lst;
	current = lst;
	while (!is_sorted(lst))
	{
		philo = (t_philosopher *)current->content;
		prev_philo = (t_philosopher *)prev->content;
		if (is_lower_than(philo, prev_philo) && philo != prev_philo)
		{
			prev->next = current->next;
			current->next = prev;
			current = lst;
			continue ;
		}
		prev = current;
		current = current->next;
	}
}
