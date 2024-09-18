/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinve <hinve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:45:37 by hpino-mo          #+#    #+#             */
/*   Updated: 2024/09/18 12:38:54 by hinve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo philos[], t_table *table)
{
	int	i;

	i = 0;
	while (i <= table->data.nb_philo)
	{
		philos[i].id = i + 1;
		philos[i].is_dead = false;
		philos[i].is_eating = false;
		philos[i].is_sleeping = false;
		philos[i].is_thinking = false;
		philos[i].is_full = 0;
		philos[i].times_eaten = 0;
		philos[i].last_meal_time = 0;
		philos[i].his_fork = &table->forks[i];
		philos[i].right_fork = &table->forks[(i + 1) % table->data.nb_philo];
		philos[i].table = table;
		i++;
	}
}

void	init_data(char **argv, t_table *table)
{
	int	i;

	i = 1;
	table->data.nb_philo = ft_atoi(argv[1]);
	table->data.t_to_die = ft_atoi(argv[2]);
	table->data.t_to_eat = ft_atoi(argv[3]);
	table->data.t_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->data.nmb_eat = ft_atoi(argv[5]);
	else
		table->data.nmb_eat = -1;
	table->data.end_program = false;
	while (i <= table->data.nb_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	table->start_time = get_time();
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->data.prove, NULL);
}
