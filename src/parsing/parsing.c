/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:59:59 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 11:31:57 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philosopher.h"

bool	ft_is_digit(int c)
{
	return (c <= '9' && c >= '0');
}

bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (false);
		i++;
	}
	return (ft_atoi(str) >= 0);
}

bool	parse_arguments(t_data *data, char **av)
{
	if (!is_valid_number(av[1]) || !is_valid_number(av[2])
		|| !is_valid_number(av[3]) || !is_valid_number(av[4]) || (av[5]
			&& av[5][0] && !is_valid_number(av[5])))
		return (false);
	data->number_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (data->number_of_philo <= 0)
		return (false);
	if (data->time_to_eat <= 0 || data->time_to_sleep <= 0
		|| data->time_to_die <= 0)
		return (false);
	if (av[5] && av[5][0])
		data->require_eat_count = ft_atoi(av[5]);
	else if (av[5] && ft_atoi(av[5]) == 0)
		data->require_eat_count = -1;
	else
		data->require_eat_count = -1;
	return (true);
}
