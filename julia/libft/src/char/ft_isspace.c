/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:04:37 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/06 11:09:44 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a given character is a whitespace character.
 *
 * This function checks if the provided character is either a space (' '),
 * or any of the following whitespace characters: 
 * 	- horizontal tab ('\t'),
 * 	- line feed ('\n'), 
 * 	- vertical tab ('\v'), 
 * 	- form feed ('\f'),
 * 	- carriage return ('\r').
 *
 * @param ch The character to check.
 * @return 1 if the character is a whitespace character, otherwise 0.
 */
int	ft_isspace(int ch)
{
	if (ch == ' ' || (ch >= '\t' && ch <= '\r'))
		return (1);
	return (0);
}
