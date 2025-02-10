/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lay.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:55:43 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 10:10:45 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philosopher.h"

void	lay_left_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_lock(&philo->mutex);
	(void)data;
	say(data, philo, "put down his left fork!", "");
}

void	lay_right_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_lock(&philo->mutex);
	(void)data;
	say(data, philo, "put down his right fork!", "");
}
