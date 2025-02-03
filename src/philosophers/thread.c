/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:00:05 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/03 10:50:33 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	*main_threads_loop(t_data *data)
{
	ft_printf(1, "Hey");
}

void	create_philosophers_threads(t_data *data)
{
	int	i;

	i = -1;
	while (data->philosophers[++i])
	{
		pthread_create(data->philosophers[i]->thread, NULL, main_threads_loop,
			(void *)data);
	}
}
