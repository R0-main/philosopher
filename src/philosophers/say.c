/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   say.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:33:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 09:20:26 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	say(t_data *data, t_philosopher *philo, const char *str1,
		const char *str2)
{
	t_time	time;

	gettimeofday(&time, 0);
	pthread_mutex_lock(&data->mutex);
	if (philo->can_talk)
		ft_fprintf(STDOUT_FILENO, "%d 	\e[1;37m🧑 Philosopher n°%d\e[0m %s %s\n",
			(size_t)((time.tv_sec - data->start_time.tv_sec) + (time.tv_usec
					- data->start_time.tv_usec) / 1000), philo->id, str1, str2);
	pthread_mutex_unlock(&data->mutex);
}
