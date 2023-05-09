/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:57:35 by emsoares          #+#    #+#             */
/*   Updated: 2023/05/03 11:14:11 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (!ft_check_args(argv))
			return (0);
		if (!ft_init_struct(argc, argv, &data))
			return (0);
		ft_threads(&data);
		ft_join_threads(&data);
		free(data.forks);
		free(data.philos);
	}
	else
		printf("Error! Check args!\n");
	return (0);
}
