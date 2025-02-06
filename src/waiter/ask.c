/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:31:16 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 09:00:54 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "timer.h"

void	ask_for_a_fork(t_data *data, t_philosopher *philosopher)
{
	t_list *lst;

	if (!philosopher)
		return ;
	lst = ft_lstnew(philosopher);
	if (!lst)
		return ;
	ft_lstadd_back(&data->waiter.queue, lst);
	philosopher->asked_forks = true;
}
