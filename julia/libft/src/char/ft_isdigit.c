/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:46:44 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:42:35 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check if character is decimal digit.
 * 
 * Decimal digits in the standard ASCII character set are any of: 
 * 0 1 2 3 4 5 6 7 8 9
 * 
 * @param ch Character to be checked, casted to an int, or EOF.
 * @return int A value different from zero (i.e., true) if indeed ch 
 * is a decimal digit. Zero (i.e., false) otherwise.
 */
int	ft_isdigit(int ch)
{
	if (ch >= 48 && ch <= 57)
		return (1);
	return (0);
}
