/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   say.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:33:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 10:54:05 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	say(t_data *data, t_philosopher *philo, const char *str1,
		const char *str2)
{
	pthread_mutex_lock(&data->mutex);
	ft_fprintf(STDOUT_FILENO, "\e[1;37m🧑 Philosopher n°%d\e[0m %s %s\n",
		philo->id, str1, str2);
	pthread_mutex_unlock(&data->mutex);
}
