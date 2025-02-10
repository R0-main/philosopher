/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lay.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:55:43 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 10:48:02 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philosopher.h"

#if GOOD_LOOKING_MESSAGE == 1

void	lay_left_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_lock(&philo->mutex);
	say(data, philo, PUT_DOWN_LEFT_FORK, "");
}

#else

void	lay_left_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_lock(&philo->mutex);
	(void)data;
}

#endif

#if GOOD_LOOKING_MESSAGE == 1

void	lay_right_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_lock(&philo->mutex);
	say(data, philo, PUT_DOWN_RIGHT_FORK, "");
}
#else

void	lay_right_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_lock(&philo->mutex);
	(void)data;
}

#endif
