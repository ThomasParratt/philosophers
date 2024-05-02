/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:28:23 by tparratt          #+#    #+#             */
/*   Updated: 2024/04/10 15:12:05 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				philo_num;
	int				num_of_philos;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				num_of_meals;
	int				meal_count;
	int				dead;
	int				all_meals_eaten;
	size_t			last_meal_time;
	size_t			start_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal;
	pthread_mutex_t	write;
	pthread_mutex_t	death;
	pthread_mutex_t	meals_flag;
}				t_philo;

int		check_args(char **argv);
void	init_philos(int num_of_philos, t_philo *philos, char **argv);
int		ft_atoi(const char *str);
void	thinking(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	death_check(t_philo *philo);
size_t	get_current_time(void);
void	print_message(t_philo *philo, char *action);
int		ft_usleep(size_t milliseconds);
void	*thread(void *philos);
int		checker_function(t_philo *philos);
int		init_mutexes(pthread_mutex_t *forks, int num_of_philos, t_philo *philo);
int		destroy_mutexes(t_philo *philos, pthread_mutex_t *forks);

#endif
