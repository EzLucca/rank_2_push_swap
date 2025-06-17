/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:09:01 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:44:59 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares up to a specified number of characters from two strings.
 *
 * This function compares the first `n` characters of the strings `s1` and `s2`.
 * It returns a positive value if `s1` is lexicographically greater than `s2`,
 * a negative value if `s1` is less than `s2`, and 0 if they are equal up to
 * the specified length or if both strings are identical up to `n` characters.
 *
 * @param s1  The first string to be compared.
 * @param s2  The second string to be compared.
 * @param n   The maximum number of characters to compare.
 * @return    A positive integer if `s1` > `s2`, a negative integer 
 * if `s1` < `s2`, or 0 if they are equal.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
