/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starvation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:27:05 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 09:48:14 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool is_starving(t_philosopher *philo)
{
	return (is_timer_finished(&philo->starvation_timer));
}
