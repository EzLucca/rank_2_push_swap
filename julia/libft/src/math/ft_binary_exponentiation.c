/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_exponentiation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:35:29 by ipersids          #+#    #+#             */
/*   Updated: 2025/04/22 12:54:50 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Computes the power of a number using exponentiation by squaring.
 * 
 * This function calculates `base^exponent` using the exponentiation 
 * by squaring method. It handles both positive and negative exponents.
 * 
 * @param base The base value to be raised to a power.
 * @param exponent The exponent value. Can be positive, negative, or zero.
 * @return double The result of `base` raised to the power of `exponent`.
 * 
 * @example
 * double result = ft_binary_exponentiation(2.0, 10); // result = 1024.0
 * double result = ft_binary_exponentiation(2.0, -2); // result = 0.25
 * 
 * @note Limitations:
 * This function may produce larger errors for extreme cases where
 * the base is very close to 1.0 and the exponent is very large,
 * due to the nature of floating-point arithmetic.
 */
double	ft_binary_exponentiation(double base, int exponent)
{
	double	res;

	res = 1.0;
	if (exponent < 0)
	{
		base = 1 / base;
		exponent = -exponent;
	}
	if (exponent == 0)
		return (res);
	if (exponent % 2 == 0)
	{
		base *= base;
		exponent /= 2;
	}
	while (exponent > 0)
	{
		if (exponent & 1)
			res *= base;
		base *= base;
		exponent >>= 1;
	}
	return (res);
}
