/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:54:22 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/30 14:49:56 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "philosopher.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void	*mythread(void *arg)
{
	int	*c;

	(void)arg;
	printf("Starting Thread Execution...\n");
	c = (int *)malloc(sizeof(4));
	*c = 4;
	printf("Finished Thread Execution...\n");
	return (c);
}

int	main(int ac, char const **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (ft_fprintf(STDERR_FILENO, HOW_TO_USE_ERROR), EXIT_SUCCESS);
	parse_arguments(&data, ac, (char **)av);
	return (EXIT_SUCCESS);
}
