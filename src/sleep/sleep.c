/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:26:27 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 17:15:37 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	custom_usleep(t_data *data, t_philosopher *philo, int duration)
{
	int sleeped;

	sleeped = 0;
	while (sleeped < duration)
	{
		sleeped += 10;
		usleep(10);
		(void)philo;
		if (r_bool(data, &data->one_of_philo_died))
			return ;
	}
}
