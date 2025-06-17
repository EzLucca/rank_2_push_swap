/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:37:26 by hutzig            #+#    #+#             */
/*   Updated: 2025/06/17 14:50:02 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This function checks if the stack is sorted in ascending order. */
bool	stack_sorting_check(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	stack_checking_dup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nb == tmp->nb)
				return (true);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (false);
}

bool	checking_syntax_error(char *str)
{
	while ((*str == 32) || (*str >= 9 && *str <= 13))
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

bool	checking_int_overflow(long nb, int sign, char c)
{
	int	d;

	d = c - '0';
	if (nb > INT_MAX / 10 || (nb == INT_MAX / 10 && d > INT_MAX % 10))
		if (sign == 1)
			return (true);
	if (nb > -(INT_MIN / 10) || (nb == -(INT_MIN / 10) && d > -(INT_MIN % 10)))
		if (sign == -1)
			return (true);
	return (false);
}

bool	checking_is_integer(char *str)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (checking_int_overflow(nb, sign, *str) == true)
			return (false);
		nb = nb * 10 + *str - '0';
		str++;
	}
	nb *= sign;
	return (true);
}
