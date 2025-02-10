/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:55:43 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 11:50:45 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philosopher.h"

#if GOOD_LOOKING_MESSAGES == 1

void	get_left_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_lock(&philo->left_fork->mutex);
	pthread_mutex_lock(&philo->mutex);
	say(data, philo, TAKE_LEFT_FORK, "");
}

#else

void	get_left_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_lock(&philo->left_fork->mutex);
	pthread_mutex_lock(&philo->mutex);
	say(data, philo, TAKE_FORK, "");
}

#endif

#if GOOD_LOOKING_MESSAGES == 1

void	get_right_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_lock(&philo->right_fork->mutex);
	pthread_mutex_lock(&philo->mutex);
	say(data, philo, TAKE_RIGHT_FORK, "");
}

#else

void	get_right_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_lock(&philo->right_fork->mutex);
	pthread_mutex_lock(&philo->mutex);
	say(data, philo, TAKE_FORK, "");
}

#endif
