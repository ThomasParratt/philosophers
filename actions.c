/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:33:57 by tparratt          #+#    #+#             */
/*   Updated: 2024/04/10 13:54:36 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_all_meals_eaten_flag(t_philo *philo)
{
	pthread_mutex_lock(&philo->meals_flag);
	if (philo->num_of_meals != -1)
	{
		if (philo->meal_count >= philo->num_of_meals)
			philo->all_meals_eaten = 1;
	}
	pthread_mutex_unlock(&philo->meals_flag);
}

void	thinking(t_philo *philo)
{
	print_message(philo, "is thinking");
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, "has taken a fork");
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		death_check(philo);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, "has taken a fork");
	print_message(philo, "is eating");
	pthread_mutex_lock(&philo->meal);
	philo->last_meal_time = get_current_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->meal);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	set_all_meals_eaten_flag(philo);
	print_message(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

void	death_check(t_philo *philo)
{
	int	timestamp;

	pthread_mutex_lock(&philo->death);
	if (philo->last_meal_time == 0)
		timestamp = get_current_time() - philo->start_time;
	else
		timestamp = get_current_time() - philo->last_meal_time;
	if (timestamp >= philo->time_to_die)
		philo->dead = 1;
	pthread_mutex_unlock(&philo->death);
}
