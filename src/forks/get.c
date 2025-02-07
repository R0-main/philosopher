/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:55:43 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 13:10:49 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philosopher.h"

void	get_left_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	say(data, philo, "has taken his left fork!", "");
}

void	get_right_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_lock(&philo->right_fork->mutex);
	say(data, philo, "has taken his right fork!", "");
}
