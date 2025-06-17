/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:10:41 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:45:11 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare two blocks of memory;
 * 
 * @param ptr1 	Pointer to first block of memory.
 * @param ptr2 	Pointer to second block of memory.
 * @param num 	Number of bytes to compare.
 * @return int 	Returns an integral value indicating the relationship between 
 * the content of the memory blocks.
 */
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	i = 0;
	str1 = (const unsigned char *)ptr1;
	str2 = (const unsigned char *)ptr2;
	while (i < num)
	{
		if (!(str1[i] == str2[i]))
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
