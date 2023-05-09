/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:28:13 by emsoares          #+#    #+#             */
/*   Updated: 2023/04/21 10:28:13 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_threads(t_data	*d)
{
	int	i;

	i = 0;
	while (i < d->nr_philo)
	{
		if (pthread_create(&d->philos[i].th, NULL,
				&ft_simulation, &d->philos[i]) != 0)
			ft_error_message("Philo thread!\n");
		usleep(1000);
		i++;
	}
	if (pthread_create(&d->monitor, NULL, &ft_monitoring, d) != 0)
		ft_error_message("Monitor thread!\n");
}
