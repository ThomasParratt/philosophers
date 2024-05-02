/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:19:16 by tparratt          #+#    #+#             */
/*   Updated: 2024/04/10 15:11:32 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	detach_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->num_of_philos)
	{
		if (pthread_detach(philos[i].thread) != 0)
			return (1);
		i++;
	}
	return (1);
}

static int	join_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->num_of_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

static int	init_threads(t_philo *philos, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < philos->num_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, &thread, &philos[i]) != 0)
			return (1);
		usleep(42);
		i++;
	}
	if (checker_function(philos) == 1)
	{
		if (detach_threads(philos) == 1)
			return (1);
	}
	else
	{
		if (join_threads(philos) == 1)
			return (1);
	}
	destroy_mutexes(philos, forks);
	return (0);
}

static int	arg_error(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int				num_of_philos;
	t_philo			philos[200];
	pthread_mutex_t	forks[200];

	if (arg_error(argc) != 0)
		return (1);
	else
	{
		if (check_args(argv) != 0)
			return (1);
		num_of_philos = ft_atoi(argv[1]);
		if (init_mutexes(forks, num_of_philos, philos) != 0)
		{
			destroy_mutexes(philos, forks);
			return (1);
		}
		init_philos(num_of_philos, philos, argv);
		if (init_threads(philos, forks) != 0)
		{
			destroy_mutexes(philos, forks);
			return (1);
		}
	}
	return (0);
}
