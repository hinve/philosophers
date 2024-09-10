#ifndef PHILO_H
# define PHILO_H

// COLORS

# define RST "\033[0m"    /* Reset to default color */
# define RED "\033[1;31m" /* Bold Red */
# define G "\033[1;32m"   /* Bold Green */
# define Y "\033[1;33m"   /* Bold Yellow */
# define B "\033[1;34m"   /* Bold Blue */
# define M "\033[1;35m"   /* Bold Magenta */
# define C "\033[1;36m"   /* Bold Cyan */
# define W "\033[1;37m"   /* Bold White */

// INCLUDES

# include <pthread.h>  // mutex: init destroy lock unlock
# include <stdio.h>    // printf
# include <stdlib.h>   // malloc free
# include <sys/time.h> // gettimeofday
						// thread: create join detach
# include <errno.h>
# include <limits.h>  // INT_MAX
# include <stdbool.h> // bool
# include <unistd.h>  // write, usleep

// STRUCTS
typedef struct s_data // ./philo 5 810 200 200 [5] nb_philo, t_to_die, t_to_eat, t_to_sleep, nmb_eat
{
	int nb_philo;
	int t_to_die;
	int t_to_eat;
	int t_to_sleep;
	int nmb_eat; // if NULL == -1
	bool end_program;
}					t_data;
typedef struct s_table
{
	t_data			data;
	pthread_mutex_t	forks[200];
	pthread_mutex_t	print;
	long long		start_time;
}					t_table;

typedef struct s_philo
{
	int				id;
	bool			is_dead;
	bool			is_eating;
	bool			is_sleeping;
	bool			is_thinking;
	bool			is_full;
	int				times_eaten;
	long long		last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*his_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
}					t_philo;


// PROTOTYPES //

// write_errors.c
void				write_error(char *str);
void				print_status(t_philo *philo, char *str);

// utils.c
int					ft_atoi(const char *str);
int					valid_arguments(char **argv);
int					only_n(char **argv);
long long			get_time(void);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

// philo.c
void				philo(char **argv);

// init.c
void				init_data(char **argv, t_table *table);
void				init_philo(t_philo *philo, t_table *table);

// threads.c
void				create_threads(t_table *table, t_philo philos[]);

#endif