/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:01:00 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/01 17:42:26 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy block of memory
 * 
 * Copies the values of num bytes from the location pointed to by source 
 * directly to the memory block pointed to by destination. The function 
 * does not check for any terminating null character in source - it always 
 * copies exactly num bytes.
 * 
 * To avoid overflows, the size of the arrays pointed to by both the destination 
 * and source parameters, shall be at least num bytes, and should not overlap.
 * (for overlapping memory blocks, ft_memmove is a safer approach).
 * 
 * @param destination Pointer to the destination array where the content 
 * is to be copied, type-casted to a pointer of type void*.
 * @param source Pointer to the source of data to be copied, type-casted 
 * to a pointer of type const void*.
 * @param num Number of bytes to copy (size_t). 
 * @return void* destination is returned.
 */
void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	char		*dest;
	const char	*src;
	size_t		i;

	dest = destination;
	src = source;
	i = 0;
	if (num == 0)
		return (destination);
	while (i < num)
	{
		dest[i] = src[i];
		i++;
	}
	return ((void *)dest);
}
