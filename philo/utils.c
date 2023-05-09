/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:57:36 by emsoares          #+#    #+#             */
/*   Updated: 2023/05/04 17:00:09 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* -Function returns the current time in milliseconds since
the Unix epoch (January 1, 1970, 00:00:00 UTC).
-Structure contains two fields: tv_sec for the number of seconds
and tv_usec for the number of microseconds since the epoch.
-gettimeofday(&time, NULL); == function to obtain the current time
The function calculates and return the time in milliseconds
 by multiplying the number of seconds by 1000
and adding the number of microseconds divided by 1000. */

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_error_message(char *str)
{
	ft_putstr_fd("Error!\n", 2);
	ft_putstr_fd(str, 2);
	return ;
}

void	ft_message(char *msg, t_philos *p)
{
	long long	time;

	mutex_lock(&p->data->mutex);
	if (p->data->died >= 1 || p->data->all_ate == p->data->nr_philo)
	{
		mutex_unlock(&p->data->mutex);
		return ;
	}
	mutex_unlock(&p->data->mutex);
	time = get_time() - p->data->time_start;
	mutex_lock(&p->data->print);
	printf("%lld %d %s", time, p->id, msg);
	mutex_unlock(&p->data->print);
	return ;
}
