/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:45:02 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/17 15:53:13 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

/**
 * @brief Convert string to long integer
 * 
 * Parses the C-string str interpreting its content as an number, 
 * which is returned as a value of type long int.
 * 
 * @param str C-string containing the representation of an integral number.
 * @return long int On success, the function returns the converted integral 
 * 		   number as a long int value. If no valid conversion could be performed,
 * 		   a zero value is returned. If the converted value would be out 
 * 		   of the range of representable values by a long int, it causes 
 * 		   undefined behavior. 
 */
long int	ft_atol(const char *str)
{
	short int		is_negative;
	long long int	res;

	is_negative = 1;
	res = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res > (res * 10 + *str - '0') && is_negative == -1)
			return (LONG_MIN);
		if (res > (res * 10 + *str - '0'))
			return (LONG_MAX);
		res *= 10;
		res += (*str - '0');
		str++;
	}
	res = (long int)(res * is_negative);
	return (res);
}
