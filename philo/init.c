/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:37:26 by emsoares          #+#    #+#             */
/*   Updated: 2023/05/04 17:03:53 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_struct(int argc, char **argv, t_data *d)
{
	d->nr_philo = ft_atoi(argv[1]);
	d->time_die = ft_atoi(argv[2]);
	d->time_eat = ft_atoi(argv[3]);
	d->time_sleep = ft_atoi(argv[4]);
	d->must_eat = -1;
	if (argc == 6)
		d->must_eat = ft_atoi(argv[5]);
	d->all_ate = 0;
	d->died = 0;
	d->time_start = get_time();
	mutex_init(&d->print);
	mutex_init(&d->mutex);
	if (d->nr_philo == 0 || d->must_eat == 0)
	{
		printf("Error! Nr of philos must be > 0 or eat limit > 0\n");
		return (0);
	}
	if (d->time_die < 0 || d->time_eat < 0 || d->time_sleep < 0)
	{
		printf("Error! Times must be > than 0\n");
		return (0);
	}
	if (!ft_init2(d))
		return (0);
	return (1);
}

int	ft_init2(t_data *d)
{
	d->forks = ft_init_forks(d->nr_philo);
	if (!d->forks)
	{
		free(d->forks);
		return (0);
	}
	d->philos = ft_init_philos(d);
	if (!d->philos)
	{
		free(d->philos);
		return (0);
	}
	return (1);
}

pthread_mutex_t	*ft_init_forks(int nr_philos)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * nr_philos);
	if (!forks)
		return (NULL);
	while (i < nr_philos)
	{
		mutex_init(&forks[i]);
		i++;
	}
	return (forks);
}

t_philos	*ft_init_philos(t_data *data)
{
	t_philos	*p;
	int			i;

	i = 0;
	p = malloc(sizeof(t_philos) * data->nr_philo);
	if (!p)
		return (NULL);
	while (i < data->nr_philo)
	{
		p[i].id = i + 1;
		p[i].last_meal = get_time();
		p[i].times_eaten = 0;
		p[i].left_fork = &data->forks[i];
		if (data->nr_philo != 1)
		{
			p[i].right_fork = &data->forks[(i + 1) % data->nr_philo];
		}
		p[i].data = data;
		mutex_init(&p[i].reaper);
		i++;
	}
	return (p);
}
