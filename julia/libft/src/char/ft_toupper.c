/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:05:42 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:44:20 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Convert lowercase letter to uppercase
 * 
 * @param ch Character to be converted, casted to an int, or EOF. 
 * @return int The uppercase equivalent to ch, if such value exists, 
 * or ch (unchanged) otherwise. The value is returned as an int value 
 * that can be implicitly casted to char.
 */
int	ft_toupper(int ch)
{
	int	diff;
	int	res;

	diff = 'a' - 'A';
	if (ch >= 97 && ch <= 122)
	{
		res = ch - diff;
		return (res);
	}
	return (ch);
}
