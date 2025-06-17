/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:47:59 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/04 14:59:12 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates the absolute value of an integer.
 *
 * @param num The integer whose absolute value is to be calculated.
 * @return The absolute value of the input integer.
 */
int	ft_abc(int num)
{
	if (num == INT_MIN)
		return (INT_MAX);
	if (num < 0)
		num = -num;
	return (num);
}
