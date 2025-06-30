/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:17:43 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 15:27:59 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Checks whether stack A is sorted in ascending order.
 *
 * Iterates through stack A and compares each node's number with the next.
 *
 * @param a Pointer to the head of stack A.
 * @return true if the stack is sorted in ascending order, false otherwise.
 */
bool	ascending_check(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !(*a))
		return (0);
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

/**
 * @brief Checks for duplicate numbers in the stack.
 *
 * Compares each number with all subsequent nodes in the stack.
 *
 * @param a Pointer to the head of the stack.
 * @return true if duplicates are found, false otherwise.
 */
bool	duplicates_check(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (true);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (false);
}

/**
 * @brief Validates the syntax of a numeric string.
 *
 * Skips whitespace and checks for optional sign and numeric digits.
 * Returns true if the string contains invalid characters.
 *
 * @param str The string to validate.
 * @return true if syntax is invalid, false if valid.
 */
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

/**
 * @brief Checks whether adding a digit to a number causes integer overflow.
 *
 * Compares the current number and digit against INT_MAX or INT_MIN thresholds
 * based on the intended sign.
 *
 * @param nbr The current accumulated number.
 * @param sign The sign of the number (1 for positive, -1 for negative).
 * @param c The next digit character to be added.
 * @return true if overflow would occur, false otherwise.
 */
bool	overflow_check(long nbr, int sign, char c)
{
	int	number;
	int	max_value;
	int	min_value;
	int	p_last_digit;
	int	n_last_digit;

	number = c - '0';
	max_value = INT_MAX / 10;
	min_value = INT_MIN / 10;
	p_last_digit = INT_MAX % 10;
	n_last_digit = INT_MIN % 10;
	if (nbr > max_value || (nbr == max_value && number > p_last_digit))
		if (sign == 1)
			return (true);
	if (nbr > -(min_value) || (nbr == -(min_value) && number > -(n_last_digit)))
		if (sign == -1)
			return (true);
	return (false);
}

/**
 * @brief Validates whether a string represents a valid 32-bit signed integer.
 *
 * Checks for proper syntax, and ensures that the number does not overflow
 * or underflow the `int` range.
 *
 * @param str The string to validate.
 * @return true if the string represents a valid int, false otherwise.
 */
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
