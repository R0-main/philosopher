/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:49:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 15:09:31 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	thinking_action(t_data *data, t_philosopher *philo)
{
	(void)data;
	if (philo->action == NONE && philo->action_timer.started == false)
	{
		trigger_action(philo, THINK, 1);
		ask_for_a_fork(data, philo);
	}
	if (philo->action == THINK && is_timer_finished(&philo->action_timer))
	{
		if (!philo->asked_forks)
			ask_for_a_fork(data, philo);
	}
}
