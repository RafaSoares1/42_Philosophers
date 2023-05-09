/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:42:37 by emsoares          #+#    #+#             */
/*   Updated: 2023/05/02 12:38:27 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				printf("Error! Passed args must contain only numbers.\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
