/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:49:42 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/03 14:52:26 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H

# define PHILOSOPHER_H

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>

# define BAD_ARGUMENTS \
	"please use valids arguments,\
 only numbers for 0 to INT_MAX are accepeted!\n"

# define MALLOC_FAILED_ON_PHILO_CREATION \
	"a malloc failled during\
 a philosopher creation\n"

# define MALLOC_FAILED_ON_FORK_CREATION \
	"a malloc failled during\
 a fork creation\n"

# define HOW_TO_USE_ERROR \
	"./philosopher \
<number_of_philosophers> \
<time_to_die> <time_to_eat> \
<time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"

typedef struct timeval	t_time;

typedef enum e_action
{
	EAT,
	SLEEP,
	THINK
}						t_e_action;

typedef struct s_philosopher
{
	int					id;
	t_e_action			action;
	t_time				last_action_date;
	pthread_t			thread;
}						t_philosopher;

typedef struct s_fork
{
	t_philosopher		*user;
}						t_fork;

typedef struct s_data
{
	bool				one_of_philo_died;
	t_philosopher		**philosophers;
	t_fork				**forks;
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					require_eat_count;
	pthread_mutex_t		mutex;
}						t_data;

typedef struct s_thread_data
{
	t_data				*data;
	t_philosopher		*philosopher;
}						t_thread_data;

//-------------------------------------------------
//
//	PARSING
//
//-------------------------------------------------

bool					parse_arguments(t_data *data, char **av);

//-------------------------------------------------
//
//	PHILOSOPHERS
//
//-------------------------------------------------

t_philosopher			*create_philosopher(int id);
void					create_philosophers_array(t_data *data);
void					free_philosophers_array(t_data *data);
t_fork					*create_fork(void);
void					create_forks_array(t_data *data);
void					free_until_end_fork(t_fork **array, int i, int max);
void					free_forks_array(t_data *data);

void					wait_for_all_threads(t_data *data);
void					create_philosophers_threads(t_data *data);

//-------------------------------------------------
//
//	UTILS
//
//-------------------------------------------------
void					free_until_end(t_philosopher **array, int i, int max);

#endif
