/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:17:33 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:47:15 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_counter(long int n);

/**
 * @brief Converts an integer to a string.
 * 
 * This function allocates memory (using malloc(3)) and 
 * returns a string representation of the integer `n`. 
 * It handles negative numbers appropriately.
 * 
 * @param n The integer to convert to a string.
 * @return char* A pointer to the string representing the integer. 
 *                Returns NULL if memory allocation fails.
 */
char	*ft_itoa(int n)
{
	long int	big_n;
	short int	is_neg;
	size_t		len;
	char		*res;

	big_n = n;
	is_neg = (n < 0);
	if (is_neg)
		big_n *= -1;
	len = ft_num_counter(big_n);
	res = (char *) malloc((len + is_neg + 1) * sizeof(char));
	if (!res)
		return (0);
	if (big_n == 0)
		res[0] = '0';
	res[len + is_neg] = '\0';
	while (big_n > 0)
	{
		len--;
		res[len + is_neg] = (big_n % 10) + '0';
		big_n /= 10;
	}
	if (is_neg)
		res[0] = '-';
	return (res);
}

// ---------------------------------------------- //
// -------------  SUPPORT FUNCTIONS ------------- //
// ---------------------------------------------- //

static size_t	ft_num_counter(long int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
