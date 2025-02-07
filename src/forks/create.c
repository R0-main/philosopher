/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:55:43 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 11:59:07 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philosopher.h"

t_fork	*create_fork(void)
{
	t_fork	*fork;

	fork = (t_fork *)malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	ft_bzero(fork, sizeof(t_fork));
	fork->used = false;
	return (fork);
}
