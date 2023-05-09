/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:52:12 by emsoares          #+#    #+#             */
/*   Updated: 2023/05/03 12:19:05 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitoring(void *arg)
{
	t_data	*d;

	d = (t_data *) arg;
	while (1)
	{
		if (check_philos_died(d))
			return (NULL);
		if (check_philos_ate(d))
			return (NULL);
	}
	return (NULL);
}

int	check_philos_died(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nr_philo)
	{
		mutex_lock(&d->philos[i].reaper);
		if ((get_time() - d->philos[i].last_meal) > d->time_die)
		{
			ft_message("died\n", &d->philos[i]);
			mutex_lock(&d->mutex);
			d->died = 1;
			mutex_unlock(&d->mutex);
			mutex_unlock(&d->philos[i].reaper);
			return (1);
		}
		mutex_unlock(&d->philos[i].reaper);
		i++;
	}
	return (0);
}

int	check_philos_ate(t_data *d)
{
	if (d->must_eat == -1)
		return (0);
	mutex_lock(&d->mutex);
	if (d->all_ate == d->nr_philo)
	{
		mutex_unlock(&d->mutex);
		return (1);
	}	
	mutex_unlock(&d->mutex);
	return (0);
}
