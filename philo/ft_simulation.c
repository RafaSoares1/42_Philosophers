/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:46:27 by emsoares          #+#    #+#             */
/*   Updated: 2023/04/20 09:46:27 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_simulation(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	if (philos->data->nr_philo == 1)
	{
		mutex_lock(philos->left_fork);
		ft_message("has taken a fork\n", philos);
		mutex_unlock(philos->left_fork);
		return (NULL);
	}
	if (philos->id % 2 == 0)
		usleep(2000);
	while (philos->data->died == 0)
	{
		if (ft_grab_forks(philos))
			return (NULL);
		if (ft_eating(philos))
			return (NULL);
		if (ft_sleeping(philos))
			return (NULL);
		if (ft_thinking(philos))
			return (NULL);
	}
	return (NULL);
}

int	ft_grab_forks(t_philos *p)
{
	mutex_lock(&p->data->mutex);
	if (p->data->died >= 1 || p->data->all_ate == p->data->nr_philo)
	{
		mutex_unlock(&p->data->mutex);
		return (1);
	}
	mutex_unlock(&p->data->mutex);
	if (p->id % 2)
	{
		mutex_lock(p->right_fork);
		ft_message("has taken a fork\n", p);
		mutex_lock(p->left_fork);
		ft_message("has taken a fork\n", p);
	}
	else
	{
		mutex_lock(p->left_fork);
		ft_message("has taken a fork\n", p);
		mutex_lock(p->right_fork);
		ft_message("has taken a fork\n", p);
	}
	return (0);
}

int	ft_eating(t_philos *p)
{
	mutex_lock(&p->data->mutex);
	if (p->data->died >= 1 || p->data->all_ate == p->data->nr_philo)
	{
		mutex_unlock(&p->data->mutex);
		mutex_unlock(p->left_fork);
		mutex_unlock(p->right_fork);
		return (1);
	}
	mutex_unlock(&p->data->mutex);
	mutex_lock(&p->reaper);
	p->last_meal = get_time();
	ft_message("is eating\n", p);
	mutex_lock(&p->data->mutex);
	p->times_eaten++;
	if (p->data->must_eat != -1)
	{
		if (p->times_eaten == p->data->must_eat)
			p->data->all_ate++;
	}
	mutex_unlock(&p->data->mutex);
	mutex_unlock(&p->reaper);
	usleep(p->data->time_eat * 1000);
	mutex_unlock(p->left_fork);
	mutex_unlock(p->right_fork);
	return (0);
}

int	ft_sleeping(t_philos *p)
{
	mutex_lock(&p->data->mutex);
	if (p->data->died >= 1 || p->data->all_ate == p->data->nr_philo)
	{
		mutex_unlock(&p->data->mutex);
		return (1);
	}
	mutex_unlock(&p->data->mutex);
	ft_message("is sleeping\n", p);
	usleep(p->data->time_sleep * 1000);
	return (0);
}

int	ft_thinking(t_philos *p)
{
	mutex_lock(&p->data->mutex);
	if (p->data->died >= 1 || p->data->all_ate == p->data->nr_philo)
	{
		mutex_unlock(&p->data->mutex);
		return (1);
	}
	mutex_unlock(&p->data->mutex);
	ft_message("is thinking\n", p);
	return (0);
}
