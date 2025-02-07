/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lay.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:55:43 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/07 13:11:05 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philosopher.h"

void	lay_left_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->left_fork->mutex);
	say(data, philo, "put down his left fork!", "");
}

void	lay_right_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->right_fork->mutex);
	say(data, philo, "put down his right fork!", "");
}
