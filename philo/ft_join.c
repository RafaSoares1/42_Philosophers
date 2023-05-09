/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:33:00 by emsoares          #+#    #+#             */
/*   Updated: 2023/05/03 12:15:48 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_join_threads(t_data *d)
{
	int	i;

	i = 0;
	if (pthread_join(d->monitor, NULL))
		ft_error_message("Join monitor !\n");
	while (i < d->nr_philo)
	{
		if (pthread_join(d->philos[i].th, NULL))
			ft_error_message("Join thread !\n");
		usleep(100);
		i++;
	}
	i = 0;
	while (i < d->nr_philo)
	{
		mutex_destroy(&d->forks[i]);
		mutex_destroy(&d->philos[i].reaper);
		i++;
	}
	mutex_destroy(&d->print);
	mutex_destroy(&d->mutex);
}
