/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:49:42 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/10 10:55:17 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H

# define PHILOSOPHER_H

# include "ft_fprintf.h"
# include "libft.h"
# include "timer.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# ifndef GOOD_LOOKING_MESSAGE
#  define GOOD_LOOKING_MESSAGE 0
# endif

# if GOOD_LOOKING_MESSAGE == 1
#  define SAY_PRINT "%d 		\e[1;37m🧑 Philosopher n°%d\e[0m %s %s\n "
#  define TAKE_LEFT_FORK "has taken his left fork!"
#  define TAKE_RIGHT_FORK "has taken his right fork!"
#  define PUT_DOWN_LEFT_FORK "put down his left fork!"
#  define PUT_DOWN_RIGHT_FORK "put down his RIGHT fork!"
#  define EATING_ACTION "eating 🍔"
#  define THINKING_ACTION "thinking 💭"
#  define SLEEPING_ACTION "sleeping 💤"
#  define NONE_ACTION "NONE ⛔"
#  define DEATH_MESSAGE "died of starvation 💀 !"
# else
#  define SAY_PRINT "%d %d %s %s\n "
#  define TAKE_FORK "has taken a fork"
#  define EATING_ACTION "is eating"
#  define THINKING_ACTION "is thinking"
#  define SLEEPING_ACTION "is sleeping"
#  define DEATH_MESSAGE "died"
#  define NONE_ACTION "NONE"
# endif

# define BAD_ARGUMENTS "please use valids arguments,\
 only numbers for 0 to INT_MAX are accepeted!\n"

# define MALLOC_FAILED_ON_PHILO_CREATION "a malloc failled during\
 a philosopher creation\n"

# define MALLOC_FAILED_ON_FORK_CREATION "a malloc failled during\
 a fork creation\n"

# define HOW_TO_USE_ERROR "./philosopher \
<number_of_philosophers> \
<time_to_die> <time_to_eat> \
<time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"

typedef struct s_data		t_data;

typedef enum e_action
{
	NONE = -1,
	EAT,
	SLEEP,
	THINK
}							t_e_action;

typedef struct s_fork
{
	bool					used;
	pthread_mutex_t			mutex;
}							t_fork;

typedef struct s_philosopher
{
	int						id;
	t_e_action				action;
	t_timer					action_timer;
	bool					can_talk;
	t_timer					eat_timer;
	t_timer					starvation_timer;
	pthread_t				thread;
	int						eat_count;
	bool					asked_forks;
	t_fork					*left_fork;
	t_fork					*right_fork;
	t_data					*data;
	pthread_mutex_t			mutex;
}							t_philosopher;

typedef struct s_doubled_list
{
	void					*content;
	struct s_doubled_list	*next;
	struct s_doubled_list	*prev;
}							t_doubled_list;

typedef struct s_waiter
{
	pthread_t				thread;
	t_doubled_list			*queue;
}							t_waiter;

typedef struct s_data
{
	bool					started;
	t_time					start_time;
	int						finished_eat;
	bool					one_of_philo_died;
	t_philosopher			*died_philo;
	t_philosopher			**philosophers;
	t_fork					**forks;
	t_waiter				waiter;
	int						number_of_philo;
	int						time_to_die;
	int						time_to_think;
	int						time_to_eat;
	int						time_to_sleep;
	int						require_eat_count;
	pthread_mutex_t			mutex;
}							t_data;

typedef struct s_thread_data
{
	t_data					*data;
	t_philosopher			*philosopher;
}							t_thread_data;

//-------------------------------------------------
//
//	PARSING
//
//-------------------------------------------------

bool						parse_arguments(t_data *data, char **av);

//-------------------------------------------------
//
//	PHILOSOPHERS
//
//-------------------------------------------------

t_philosopher				*create_philosopher(int id);
void						create_philosophers_array(t_data *data);
void						free_philosophers_array(t_data *data);
t_fork						*create_fork(void);
void						create_forks_array(t_data *data);
void						free_until_end_fork(t_fork **array, int i, int max);
void						free_forks_array(t_data *data);
void						link_forks_with_philosophers(t_data *data);
void						trigger_action(t_data *data, t_philosopher *philo,
								t_e_action action);

void						say(t_data *data, t_philosopher *philo,
								const char *str1, const char *str2);
void						wait_for_all_threads(t_data *data);
void						print_action(t_data *data, t_philosopher *philo,
								t_e_action action, bool start);
void						create_waiter_thread(t_data *data);
void						create_philosophers_threads(t_data *data);
void						ask_for_a_fork(t_data *data,
								t_philosopher *philosopher);
bool						is_starving(t_philosopher *philo);

void						handle_actions(t_data *data, t_philosopher *philo);
void						sleeping_action(t_data *data, t_philosopher *philo);
void						eating_action(t_data *data, t_philosopher *philo);
void						thinking_action(t_data *data, t_philosopher *philo);

void						get_left_fork(t_data *data, t_philosopher *philo);
void						get_right_fork(t_data *data, t_philosopher *philo);
void						lay_left_fork(t_data *data, t_philosopher *philo);
void						lay_right_fork(t_data *data, t_philosopher *philo);

//-------------------------------------------------
//
//	UTILS
//
//-------------------------------------------------
void						free_until_end(t_philosopher **array, int i,
								int max);

void						ft_dlstadd_back(t_doubled_list **alst,
								t_doubled_list *new);
void						ft_dlstclear(t_doubled_list **lst);
t_doubled_list				*ft_dlstlast(t_doubled_list *lst);
t_doubled_list				*ft_dlstnew(void *content);

void						ft_dlstremoveone(t_doubled_list **head,
								t_doubled_list *lst);

bool						r_bool(pthread_mutex_t *mutex, bool *property);
int							r_int(t_data *data, int *property);
t_philosopher				r_philosopher(t_data *data, t_philosopher property);

void						w_bool(pthread_mutex_t *mutex, bool *property,
								bool value);
bool						custom_usleep(t_data *data, t_philosopher *philo,
								long duration);

#endif
