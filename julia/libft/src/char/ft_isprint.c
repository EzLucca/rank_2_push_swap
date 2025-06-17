/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:50:23 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:42:59 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Test if a ch passed as the argument is a printable character.
 * 
 * Printable characters in C are: digits, letters, punctuation characters 
 * ( !”#$%&'()*+,-./:;?@[\]^_`{ | }~ ) and space.
 * 
 * @param ch the character to be checked.
 * @return int It returns a non-zero value(true) if the given ch is printable.
 * Overwise, it returns zero (false).
 */
int	ft_isprint(int ch)
{
	if (ch >= 32 && ch <= 126)
		return (1);
	return (0);
}
