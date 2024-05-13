/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:48:58 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/12 15:52:52 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	check_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	long	numbers;
	int		count;

	numbers = 0;
	count = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		return (0);
	while (*str == '0')
		str++;
	if (!check_digit(str))
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		numbers = numbers * 10 + (*str - 48);
		str++;
		count++;
	}
	if (count > 10 || numbers > INT_MAX)
		return (-1);
	return (numbers);
}
