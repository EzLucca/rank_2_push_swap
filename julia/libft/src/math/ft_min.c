/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:04:15 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/20 10:35:51 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Returns the minimum of two integers.
 * 
 * @param n1 The first integer to compare.
 * @param n2 The second integer to compare.
 * @return int The smallest of the two integers.
 */
int	ft_min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}
