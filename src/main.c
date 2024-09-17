/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpino-mo <hpino-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:01:25 by hpino-mo          #+#    #+#             */
/*   Updated: 2024/09/17 11:47:46 by hpino-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv) // argv == ./philo 5 810 200 200 [5]
{
	if ((argc == 5 || argc == 6) && valid_arguments(argv))
		philo(argv);
}
