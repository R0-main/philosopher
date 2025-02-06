/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   say.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:33:49 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/06 14:44:04 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	say(t_philosopher *philo, const char *str1, const char *str2)
{
	ft_fprintf(STDOUT_FILENO, "\e[1;37m🧑 Philosopher n°%d\e[0m %s %s\n", philo->id, str1, str2);
}
