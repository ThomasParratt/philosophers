/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:30:04 by tparratt          #+#    #+#             */
/*   Updated: 2024/04/08 17:12:30 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *) philos;
	while (philo->dead != 1 && philo->all_meals_eaten != 1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

int	checker_function(t_philo *philos)
{
	int	i;
	int	count;

	while (1)
	{
		i = 0;
		count = 0;
		death_check(philos);
		while (i < philos->num_of_philos)
		{
			if (philos[i].all_meals_eaten == 1)
				count++;
			if (count == philos[i].num_of_philos)
				return (1);
			if (philos[i].dead == 1)
			{
				print_message(philos, "died");
				return (1);
			}
			i++;
		}
	}
	return (0);
}
