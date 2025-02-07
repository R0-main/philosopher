/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 10:54:49 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_dlstadd_back(t_doubled_list **alst, t_doubled_list *new)
{
	t_doubled_list	*last;

	if (!alst || !new)
		return ;
	last = ft_dlstlast(*alst);
	if (!last)
	{
		*alst = new;
	}
	else
	{
		new->prev = last;
		last->next = new;
	}
}
