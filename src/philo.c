# include "philo.h"

void init_all(t_table *table, char **argv, t_philo *philo)
{
    init_data(argv, table);
    init_philo(philo, table);
}

void philo(char **argv)
{
    t_table table;
    t_philo philo[200];

    init_all(&table, argv, philo);
    create_threads(&table, philo);
}
