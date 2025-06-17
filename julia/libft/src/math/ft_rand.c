/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:01:20 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/04 15:11:01 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Pseudo-random integer value
 * 
 * This function uses a linear congruential generator (LCG):
 * X_{n+1} = (a * X_n + c) mod m
 * where:
 *   - x is the sequence of pseudo-random values,
 *   - m is the modulus (2^31),
 *   - a is the multiplier (0 < a <= m),
 *   - c is the increment (0 <= c < m, odd number),
 *   - X_0 is the seed (0 <= X_0 < m).
 *   - RAND_MAX 0x7FFFFFFF (2^31 - 1, stdlib.h)
 * 
 * @return int Pseudo-random integer value (non-negative).
 */
int	ft_rand(void)
{
	static unsigned int	x = 2622054;
	const unsigned int	m = 0x80000000;
	const unsigned int	a = 37769685;
	const unsigned int	c = 12345;

	x = (a * x + c) % m;
	return ((int)(x & RAND_MAX));
}
