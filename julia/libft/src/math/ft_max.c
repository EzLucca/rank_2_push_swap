/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:33:59 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/20 10:39:40 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Returns the maximum of two integers.
 * 
 * @param n1 The first integer to compare.
 * @param n2 The second integer to compare.
 * @return int The greater of the two integers.
 */
int	ft_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}
