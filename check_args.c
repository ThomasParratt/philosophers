/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:08:52 by tparratt          #+#    #+#             */
/*   Updated: 2024/03/22 09:42:26 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (is_whitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		if (num > 2147483647 / 10 || (num == 2147483647 / 10 && *str - '0' > 7))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		num = num * 10 + (*str++ - '0');
	}
	return (num * sign);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' && !num[1])
		return (1);
	if (num[0] == '-')
		return (1);
	if (num[0] == '0')
		return (1);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isnum(argv[i]) != 0)
		{
			printf("Error: Arguments must all be positive integers\n");
			return (1);
		}
		i++;
	}
	return (0);
}
