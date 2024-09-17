/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpino-mo <hpino-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:45:54 by hpino-mo          #+#    #+#             */
/*   Updated: 2024/09/17 11:47:55 by hpino-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (check_death(philo) == false)
	{
		if (philo->table->data.nmb_eat != -1
			&& philo->times_eaten >= philo->table->data.nmb_eat)
			break ;
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		ft_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	*routine_one(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("0 1 has taken his fork\n");
	usleep(philo->table->data.t_to_die * 1000);
	printf("%lld 1 died\n", get_time() - philo->table->start_time + 1);
	return (NULL);
}
