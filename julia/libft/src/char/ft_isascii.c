/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:49:08 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:42:49 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Test a character to see if it's a 7-bit ASCII character
 * 
 * The ft_isascii() function tests for an ASCII character 
 * (in the range 0 to 127).
 * 
 * @param ch Character to be checked, casted to an int, or EOF.
 * @return int A value different from zero (i.e., true) if indeed ch 
 * is an ASCII character. Zero (i.e., false) otherwise.
 */
int	ft_isascii(int ch)
{
	if (ch >= 0 && ch <= 127)
		return (1);
	return (0);
}
