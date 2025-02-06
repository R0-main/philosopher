/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremoveone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 11:18:30 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdio.h>

void	ft_dlstremoveone(t_doubled_list **head, t_doubled_list *lst)
{
	t_doubled_list	*tmp;

	if (!lst || !head)
		return ;
	tmp = lst;
	if (lst->prev)
		lst->prev->next = lst->next;
	else
		*head = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	free(tmp);
}
