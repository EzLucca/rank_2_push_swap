/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:17:43 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/24 18:11:42 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

bool	ascending_check(t_stack **st_a)
{
	t_stack	*tmp;

	tmp = *st_a;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	duplicates_check(t_stack *st_a)
{
	t_stack	*tmp;

	while (st_a)
	{
		tmp = st_a->next;
		while (tmp)
		{
			if (st_a->nbr == tmp->nbr)
				return (true);
			tmp = tmp->next;
		}
		st_a = st_a->next;
	}
	return (false);
}

bool	syntax_check(char *str)
{
	while ((*str == ' ') || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (true);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (true);
		str++;
	}
	return (false);
}

// Check 
bool	overflow_check(long nbr, int sign, char c)
{
	int	number;

	number = c - '0';
	if (nbr > INT_MAX / 10 || (nbr == INT_MAX / 10 && number > INT_MAX % 10))
		if (sign == 1)
			return (true);
	if (nbr > -(INT_MIN / 10)
			|| (nbr == -(INT_MIN / 10) && number > -(INT_MIN % 10)))
		if (sign == -1)
			return (true);
	return (false);
}

bool	int_check(char *str)
{
	int		sign;
	long	nbr;

	sign = 1;
	nbr = 0;
	while ((*str == ' ') || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (overflow_check(nbr, sign, *str) == true)
			return (false);
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	nbr *= sign;
	return (true);
}
