/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 10:19:59 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	trigger_action(t_philosopher *philo, t_e_action action, int duration)
{
	(void)duration;
	philo->action = action;
	print_action(philo, true);
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

void	print_action(t_philosopher *philo, bool start)
{
	const char	*action_name;

	action_name = get_action_name(philo->action);
	if (start)
		say(philo, "\033[1;32mstarts\033[0m", action_name);
	else
		say(philo, "\033[1;31mfinished\033[0m", action_name);
}

void	handle_actions(t_data *data, t_philosopher *philo)
{
	if (philo->action == NONE && philo->id % 2 == 0)
	{
		pthread_mutex_lock(&data->mutex);
		philo->action = EAT;
		philo->starvation_timer.duration = data->time_to_die;
		start_timer(&philo->starvation_timer);
		pthread_mutex_unlock(&data->mutex);
	}
	else if (philo->action == NONE)
	{
		pthread_mutex_lock(&data->mutex);
		philo->action = THINK;
		print_action(philo, true);
		philo->starvation_timer.duration = data->time_to_die;
		start_timer(&philo->starvation_timer);
		pthread_mutex_unlock(&data->mutex);
	}
	eating_action(data, philo);
	sleeping_action(data, philo);
	thinking_action(data, philo);
}
