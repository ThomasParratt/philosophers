/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:50:20 by tparratt          #+#    #+#             */
/*   Updated: 2024/04/10 14:50:47 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_forks(pthread_mutex_t *forks, int num, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < num)
	{
		philo[i].left_fork = &forks[i];
		if (i == 0)
			philo[i].right_fork = &forks[num - 1];
		else
			philo[i].right_fork = &forks[i - 1];
		i++;
	}
	return (0);
}

int	init_mutexes(pthread_mutex_t *forks, int num_of_philos, t_philo *philo)
{
	if (init_forks(forks, num_of_philos, philo) != 0)
		return (1);
	if (pthread_mutex_init(&philo->meal, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&philo->write, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&philo->death, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&philo->meals_flag, NULL) != 0)
		return (1);
	return (0);
}

int	destroy_mutexes(t_philo *philos, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < philos->num_of_philos)
	{
		if (pthread_mutex_destroy(&forks[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_destroy(&philos->meal) != 0)
		return (1);
	if (pthread_mutex_destroy(&philos->write) != 0)
		return (1);
	if (pthread_mutex_destroy(&philos->death) != 0)
		return (1);
	if (pthread_mutex_destroy(&philos->meals_flag) != 0)
		return (1);
	return (0);
}
