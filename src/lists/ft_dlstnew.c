/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 10:35:56 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philosopher.h"
#include "garbadge.h"

t_doubled_list	*ft_dlstnew(void *content)
{
	t_doubled_list	*result;

	result = malloc(sizeof(t_doubled_list));
	if (!result)
		return (NULL);
	result->content = content;
	result->prev = NULL;
	result->next = NULL;
	return (result);
}
