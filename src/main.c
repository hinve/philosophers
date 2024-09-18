/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinve <hinve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:01:25 by hpino-mo          #+#    #+#             */
/*   Updated: 2024/09/18 12:43:59 by hinve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int only_n(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write_error("Arguments must be numbers");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv) // argv == ./philo 5 810 200 200 [5]
{
	if ((argc == 5 || argc == 6) && valid_arguments(argv) && only_n(argv))
		philo(argv);
}
