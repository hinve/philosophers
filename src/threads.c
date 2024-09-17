/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpino-mo <hpino-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:45:56 by hpino-mo          #+#    #+#             */
/*   Updated: 2024/09/17 11:46:39 by hpino-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	if (philo->table->data.end_program == true)
	{
		pthread_mutex_unlock(&philo->table->print);
		return (true);
	}
	pthread_mutex_unlock(&philo->table->print);
	return (false);
}

void	*monitor(void *data)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)data;
	while (1)
	{
		i = 0;
		while (i < philos->table->data.nb_philo)
		{
			pthread_mutex_lock(&philos->table->print);
			if ((get_time() - philos[i].table->start_time)
				- philos[i].last_meal_time > philos->table->data.t_to_die)
			{
				philos[i].is_dead = true;
				print_status(&philos[i], "died");
				philos->table->data.end_program = true;
				pthread_mutex_unlock(&philos->table->print);
				return (NULL);
			}
			pthread_mutex_unlock(&philos->table->print);
			i++;
		}
	}
	return (NULL);
}

void	just_one(t_philo philo[])
{
	pthread_create(&philo[0].thread, NULL, &routine_one, (void *)&philo[0]);
	pthread_join(philo[0].thread, NULL);
}

void	create_threads(t_table *table, t_philo philos[])
{
	pthread_t	moni;
	int			i;

	i = 0;
	if (table->data.nb_philo == 1)
		just_one(philos);
	else
	{
		pthread_create(&moni, NULL, &monitor, (void *)philos);
		while (i < table->data.nb_philo)
		{
			pthread_create(&philos[i].thread, NULL, &routine,
				(void *)&philos[i]);
			i++;
		}
		i = 0;
		while (i < table->data.nb_philo)
		{
			pthread_join(philos[i].thread, NULL);
			i++;
		}
		pthread_join(moni, NULL);
	}
}
