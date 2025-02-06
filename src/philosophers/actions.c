/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 09:31:15 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	trigger_action(t_philosopher *philo, t_e_action action, int duration)
{
	philo->action = action;
	philo->action_timer.duration = duration;
	start_timer(&philo->action_timer);
	if (action == EAT)
		start_timer(&philo->starvation_timer);
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
		say(philo, "starts", action_name);
	else
		say(philo, "finished", action_name);
}
