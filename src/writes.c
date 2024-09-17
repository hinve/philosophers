/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpino-mo <hpino-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:46:02 by hpino-mo          #+#    #+#             */
/*   Updated: 2024/09/17 11:46:55 by hpino-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_error(char *str)
{
	printf(RED "Error: %s\n" RST, str);
}

void	print_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->data.prove);
	if (philo->table->data.end_program == false)
		printf("%lld %d %s\n", get_time() - philo->table->start_time, philo->id,
			str);
	pthread_mutex_unlock(&philo->table->data.prove);
}
