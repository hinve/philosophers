#include "philo.h"

void	write_error(char *str)
{
	printf(RED "Error: %s\n" RST, str);
}

void print_status(t_philo *philo, char *str)
{
    if (philo->table->data.end_program == false)
        printf("%lld %d %s\n", get_time() - philo->table->start_time, philo->id, str);
}