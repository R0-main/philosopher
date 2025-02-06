/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 11:50:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	test(void *ptr)
{
	t_philosopher *p;

	p = (t_philosopher *)ptr;
	say(p, "hey", "");
}

void	ft_dlstadd_back(t_doubled_list **alst, t_doubled_list *new)
{
	t_doubled_list	*last;

	if (!alst || !new)
		return ;
	last = ft_dlstlast(*alst);
	// ft_lstiter((t_list *)*alst, test);
	if (!last)
	{
		*alst = new;
	}
	else
	{
		new->prev = last;
		last->next = new;
	}
	// ft_lstiter((t_list *)*alst, test);
}
