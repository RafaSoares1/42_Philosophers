/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:57:39 by emsoares          #+#    #+#             */
/*   Updated: 2023/05/03 12:16:14 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_data
{
	int							nr_philo;
	int							time_die;
	int							time_eat;
	int							time_sleep;
	int							must_eat;
	int							all_ate;
	int							died;
	long long					time_start;
	pthread_mutex_t				mutex;
	pthread_mutex_t				print;
	struct s_philos				*philos;
	pthread_mutex_t				*forks;
	pthread_t					monitor;
}	t_data;

typedef struct s_philos
{
	int							id;
	int							times_eaten;
	long long					last_meal;
	pthread_t					th;
	pthread_mutex_t				*right_fork;
	pthread_mutex_t				*left_fork;
	pthread_mutex_t				reaper;
	t_data						*data;
}	t_philos;

//main
int							main(int argc, char **argv);

//check
int							ft_check_args(char **argv);

//join
void						ft_join_threads(t_data *d);

//monitoring
void						*ft_monitoring(void *arg);
int							check_philos_died(t_data *d);
int							check_philos_ate(t_data *d);

//threads
void						ft_threads(t_data	*data);

//init
int							ft_init_struct(int argc, char **argv, t_data *d);
int							ft_init2(t_data *d);
pthread_mutex_t				*ft_init_forks(int nr_philos);
t_philos					*ft_init_philos(t_data *data);

//utils
void						ft_error_message(char *str);
void						ft_message(char *msg, t_philos *p);
long long					get_time(void);

//simulation
void						*ft_simulation(void *arg);
int							ft_grab_forks(t_philos *p);
int							ft_eating(t_philos *p);
int							ft_sleeping(t_philos *p);
int							ft_thinking(t_philos *p);

//ft_libft
void						ft_putstr_fd(char *s, int fd);
int							ft_isdigit(int c);
int							ft_atoi(const char *str);

//mutex_shortcut
void						mutex_init(pthread_mutex_t *mutex);
void						mutex_lock(pthread_mutex_t *mutex);
void						mutex_unlock(pthread_mutex_t *mutex);
void						mutex_destroy(pthread_mutex_t *mutex);
#endif