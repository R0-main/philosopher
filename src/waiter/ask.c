/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:31:16 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 15:09:44 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "timer.h"

void	ask_for_a_fork(t_data *data, t_philosopher *philosopher)
{
	t_doubled_list	*lst;

	if (!philosopher)
		return ;
	lst = ft_dlstnew(philosopher);
	if (!lst)
		return ;
	ft_dlstadd_back(&data->waiter.queue, lst);
	philosopher->asked_forks = true;
	say(philosopher, "asked for a fork 🍴 !", "");
}
