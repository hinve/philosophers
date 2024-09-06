#ifndef PHILO_H
#define PHILO_H

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

# include <stdlib.h> // malloc free
# include <stdio.h> // printf
# include <sys/time.h> // gettimeofday
# include <pthread.h> // mutex: init destroy lock unlock
                      // thread: create join detach
# include <unistd.h> // write, usleep
# include <stdbool.h> // bool
# include <limits.h> // INT_MAX
# include <errno.h>

// STRUCTS
typedef struct s_data
{

} t_data;

// PROTOTYPES //

// write_errors.c
void write_error(char *str);



#endif