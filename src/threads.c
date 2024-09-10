# include "philo.h"

int is_anybody_dead(t_philo philos[])
{
    int i;

    i = 0;
    while (i < philos->table->data.nb_philo)
    {
        if (philos[i].is_dead == true)
            return (1);
        i++;
    }
    return (0);
}

void take_forks(t_philo *philo)
{
    if(!is_anybody_dead(philo))
    {
        pthread_mutex_lock(philo->his_fork);
        print_status(philo, "has taken his fork");
        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "has taken right fork");
    }
}

void eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->table->print);
    print_status(philo, "is eating");
    philo->last_meal_time = get_time();
    pthread_mutex_unlock(&philo->table->print);
    usleep(philo->table->data.t_to_eat * 1000);
    philo->times_eaten++;
}

void put_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->his_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void ft_sleep(t_philo *philo)
{
    pthread_mutex_lock(&philo->table->print);
    print_status(philo, "is sleeping");
    pthread_mutex_unlock(&philo->table->print);
    usleep(philo->table->data.t_to_sleep * 1000);
}

void think(t_philo *philo)
{
    pthread_mutex_lock(&philo->table->print);
    print_status(philo, "is thinking");
    pthread_mutex_unlock(&philo->table->print);
}

void assing_dead(t_philo *philo)
{
    if (get_time() - philo->last_meal_time > philo->table->data.t_to_die)
    {
        pthread_mutex_lock(&philo->table->print);
        philo->is_dead = true;
        pthread_mutex_unlock(&philo->table->print);
    }
}

void *monitor(void *data)
{
    t_philo *philos = (t_philo *)data;
    int i;

    while (1)
    {
        i = 0;
        while (i < philos->table->data.nb_philo)
        {
            if ((get_time() - philos[i].table->start_time) - philos[i].last_meal_time > philos->table->data.t_to_die)
            {
                pthread_mutex_lock(&philos->table->print);
                philos[i].is_dead = true;
                print_status(&philos[i], "died");
                philos->table->data.end_program = true;
                pthread_mutex_unlock(&philos->table->print);
                return NULL;
            }
            i++;
        } 
    }
    return NULL;
}

bool check_death(t_philo *philo)
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

void *routine(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    if (philo->id % 2 == 0)
        usleep(100);
    while (check_death(philo) == false)
    {
        if (philo->table->data.nmb_eat != -1 && philo->times_eaten >= philo->table->data.nmb_eat)
            break ;
        take_forks(philo);
        eat(philo);
        put_forks(philo);
        ft_sleep(philo);
        think(philo);
    }
    return (NULL);
}

void *routine_one(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    printf("0 1 has taken his fork\n");
    usleep(philo->table->data.t_to_die * 1000);
    printf("%lld 1 died\n", get_time() - philo->table->start_time + 1);
    return (NULL);
}

void just_one(t_philo philo[])
{
    pthread_create(&philo[0].thread, NULL, &routine_one, (void *)&philo[0]);
    pthread_join(philo[0].thread, NULL);
}

void create_threads(t_table *table, t_philo philos[])
{
    pthread_t moni;
    int i;

    i = 0;
    if(table->data.nb_philo == 1)
    {
        just_one(philos);
        return ;
    }
    else
    {
        pthread_create(&moni, NULL, &monitor, (void *)philos);
        while (i < table->data.nb_philo)
        {
            pthread_create(&philos[i].thread, NULL, &routine, (void *)&philos[i]);
            i++;
        }
        i = 0;
        while (i < table->data.nb_philo)
        {
            pthread_join(philos[i].thread, NULL);
            i++;
        }
    }
}
