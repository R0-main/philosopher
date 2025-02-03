/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:55:43 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/03 09:29:19 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philosopher.h"

t_fork	*create_fork(void)
{
	t_fork	*philo;

	philo = (t_fork *)malloc(sizeof(t_fork));
	if (!philo)
		return (NULL);
	ft_bzero(philo, sizeof(t_fork));
	philo->user = NULL;
	return (philo);
}

void	create_forks_array(t_data *data)
{
	int		i;
	t_fork	**array;

	i = 0;
	data->forks = NULL;
	array = (t_fork **)malloc(sizeof(t_fork *) * (data->number_of_philo + 1));
	if (!array)
		return ;
	ft_bzero(array, sizeof(t_fork *) * (data->number_of_philo + 1));
	array[data->number_of_philo] = NULL;
	while (i < data->number_of_philo)
	{
		array[i] = create_fork();
		if (array[i] == NULL)
		{
			free_until_end_fork(array, 0, data->number_of_philo);
			return ;
		}
		i++;
	}
	data->forks = array;
}
