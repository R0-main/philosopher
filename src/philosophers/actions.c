/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/05 15:25:01 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	trigger_action(t_philosopher *philo, t_e_action action, int duration)
{
	philo->action = action;
	philo->action_timer.duration = duration;
	start_timer(&philo->action_timer);
	print_action(philo, true);
}

static const char	*get_action_name(t_e_action action)
{
	if (action == EAT)
		return ("eating");
	if (action == SLEEP)
		return ("sleeping");
	if (action == THINK)
		return ("thinking");
	return ("undifined");
}

void	print_action(t_philosopher *philo, bool start)
{
	const char	*action_name;

	action_name = get_action_name(philo->action);
	if (start)
		ft_fprintf(STDOUT_FILENO, "Philosopher n°%d starts %s!\n", philo->id,
			action_name);
	else
		ft_fprintf(STDOUT_FILENO, "Philosopher n°%d finished %s!\n", philo->id,
			action_name);
}
