/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   say.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:33:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/05 15:38:07 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	say(t_philosopher *philo, const char *str1, const char *str2)
{
	ft_fprintf(STDOUT_FILENO, "Philosopher n°%d %s %s\n", philo->id, str1, str2);
}
