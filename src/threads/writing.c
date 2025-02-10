/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:32:45 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 08:28:51 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	w_bool(pthread_mutex_t *mutex, bool *property, bool value)
{
	(void)mutex;
	pthread_mutex_lock(mutex);
	*property = value;
	pthread_mutex_unlock(mutex);
}
