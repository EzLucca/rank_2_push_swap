/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:06:22 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:44:25 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Convert uppercase letter to lowercase
 * 
 * @param ch Character to be converted, casted to an int, or EOF. 
 * @return int The lowercase equivalent to ch, if such value exists, 
 * or ch (unchanged) otherwise. The value is returned as an int value 
 * that can be implicitly casted to char.
 */
int	ft_tolower(int ch)
{
	int	diff;
	int	res;

	diff = 'a' - 'A';
	if (ch >= 65 && ch <= 90)
	{
		res = ch + diff;
		return (res);
	}
	return (ch);
}
