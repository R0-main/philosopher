/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 09:25:07 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	trigger_action(t_data *data, t_philosopher *philo, t_e_action action)
{
	if (philo->action != NONE && philo->action != action)
		print_action(data, philo, philo->action, false);
	pthread_mutex_lock(&data->mutex);
	philo->action = action;
	pthread_mutex_unlock(&data->mutex);
	print_action(data, philo, action, true);
}

static const char	*get_action_name(t_e_action action)
{
	if (action == EAT)
		return ("eating 🍔");
	if (action == SLEEP)
		return ("sleeping 💤");
	if (action == THINK)
		return ("thinking 💭");
	return ("undifined");
}

void	print_action(t_data *data, t_philosopher *philo, t_e_action action,
		bool start)
{
	const char	*action_name;

	action_name = get_action_name(action);
	if (start)
		say(data, philo, "\033[1;32mstarts\033[0m", action_name);
	else
		say(data, philo, "\033[1;31mfinished\033[0m", action_name);
}

void	handle_actions(t_data *data, t_philosopher *philo)
{
	if (philo->action == NONE && philo->id % 2 == 0)
	{
		print_action(data, philo, THINK, true);
		start_timer(&philo->starvation_timer);
		philo->action = EAT;
	}
	else if (philo->action == NONE)
	{
		trigger_action(data, philo, THINK);
		start_timer(&philo->starvation_timer);
	}
	sleeping_action(data, philo);
	thinking_action(data, philo);
	eating_action(data, philo);
}
