/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:32:50 by tparratt          #+#    #+#             */
/*   Updated: 2024/04/10 15:11:45 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(int num_of_philos, t_philo *philos, char **argv)
{
	int				i;

	i = 0;
	while (i < num_of_philos)
	{
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			philos[i].num_of_meals = ft_atoi(argv[5]);
		else
			philos[i].num_of_meals = -1;
		philos[i].philo_num = i + 1;
		philos[i].num_of_philos = num_of_philos;
		philos[i].start_time = get_current_time();
		philos[i].last_meal_time = 0;
		philos[i].meal_count = 0;
		philos[i].all_meals_eaten = 0;
		philos[i].dead = 0;
		i++;
	}
}

void	print_message(t_philo *philo, char *action)
{
	int	timestamp;

	pthread_mutex_lock(&philo->write);
	timestamp = get_current_time() - philo->start_time;
	printf("%d %d %s\n", timestamp, philo->philo_num, action);
	pthread_mutex_unlock(&philo->write);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
