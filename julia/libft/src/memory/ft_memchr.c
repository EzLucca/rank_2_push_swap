/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:09:44 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:45:07 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate character in block of memory.
 * 
 * Searches within the first `num` bytes of the block of memory pointed 
 * by `ptr` for the first occurrence of `value`, and returns a pointer to it.
 * The value is passed as an int, but the function performs a byte per byte 
 * search using the unsigned char conversion of this value.
 * 
 * @param ptr 	Pointer to the block of memory where the search is performed.
 * @param value Value to be located. 
 * @param num 	Number of bytes to be analyzed.
 * 
 * @return void* A pointer to the first occurrence of value in the block 
 * of memory pointed by ptr. If the value is not found, the function 
 * returns a null pointer.
 */
void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char		ch;
	const unsigned char	*ch_ptr;
	size_t				i;

	ch = (unsigned char)value;
	ch_ptr = (const unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		if (ch_ptr[i] == ch)
			return ((void *)(ptr + i));
		i++;
	}
	return (0);
}
