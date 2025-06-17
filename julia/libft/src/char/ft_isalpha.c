/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:45:18 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:42:27 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check if character ch is alphabetic.
 * 
 * The function checks if the character lies within the ASCII ranges 
 * of alphabetic characters (a–z and A–Z). Lowercase letters: ASCII values 
 * from 97 ('a') to 122 ('z'). Uppercase letters: ASCII values from 65 ('A') 
 * to 90 ('Z').
 *
 * @param ch Character to be checked, casted to an int, or EOF.
 * @return int Non-zero value (true): If the ch is an alphabetic letter 
 * (a–z or A–Z). Zero (false): If the character is not an alphabetic letter.
 */
int	ft_isalpha(int ch)
{
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
		return (1);
	return (0);
}
