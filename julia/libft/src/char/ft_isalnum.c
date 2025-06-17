/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:48:05 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:42:42 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check if character is alphanumeric
 * 
 * The function checks if the character lies within the ASCII ranges 
 * of alphabetic characters (a–z and A–Z) or is any of numeric: 
 * 0 1 2 3 4 5 6 7 8 9
 *
 * @param ch Character to be checked, casted to an int, or EOF.
 * @return int Non-zero value (true): If the ch is an alphanumeric letter 
 * (a–z or A–Z). Zero (false): If the character is not an alphanumeric letter.
 */
int	ft_isalnum(int ch)
{
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
		return (1);
	if (ch >= 48 && ch <= 57)
		return (1);
	return (0);
}
