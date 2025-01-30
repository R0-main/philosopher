/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:49:42 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/30 14:43:00 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H

# define PHILOSOPHER_H

# include <stdbool.h>

# define HOW_TO_USE_ERROR "./philosopher \
<number_of_philosophers> \
<time_to_die> <time_to_eat> \
<time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"

typedef enum e_action
{
	EAT,
	SLEEP,
	THINK
}				t_e_action;

typedef struct s_philosopher
{
	t_e_action	action;
}				t_philosopher;

typedef struct s_data
{
	bool		one_of_philo_died;
	int			number_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			require_eat_count;
}				t_data;

//-------------------------------------------------
//
//	PARSING
//
//-------------------------------------------------

void			parse_arguments(t_data *data, int ac, char **av);

//-------------------------------------------------
//
//	UTILS
//
//-------------------------------------------------

#endif
