/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpino-mo <hpino-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:45:45 by hpino-mo          #+#    #+#             */
/*   Updated: 2024/09/17 11:46:28 by hpino-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (!check_death(philo))
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->right_fork);
			print_status(philo, "has taken right fork");
			pthread_mutex_lock(philo->his_fork);
			print_status(philo, "has taken his fork");
		}
		else
		{
			pthread_mutex_lock(philo->his_fork);
			print_status(philo, "has taken his fork");
			pthread_mutex_lock(philo->right_fork);
			print_status(philo, "has taken right fork");
		}
	}
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	print_status(philo, "is eating");
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->table->print);
	usleep(philo->table->data.t_to_eat * 1000);
	philo->times_eaten++;
	if (philo->times_eaten == philo->table->data.nmb_eat)
		philo->is_full = true;
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->his_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	print_status(philo, "is sleeping");
	pthread_mutex_unlock(&philo->table->print);
	usleep(philo->table->data.t_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	print_status(philo, "is thinking");
	pthread_mutex_unlock(&philo->table->print);
}
