/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:53:20 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:43:26 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fill block of memory.
 * 
 * Sets the first num bytes of the block of memory pointed by ptr 
 * to the specified value (interpreted as an unsigned char).
 * 
 * @param ptr 		Pointer to the block of memory to fill.
 * @param value 	Value to be set. The value is passed as an int, 
 * but the function fills the block of memory using the unsigned char 
 * conversion of this value.
 * @param num 		Number of bytes to be set to the value. 
 * `size_t` is an unsigned integral type.
 * @return void* ptr is returned.
 */
void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*ch_ptr;

	i = 0;
	ch = (unsigned char)value;
	ch_ptr = (unsigned char *)ptr;
	while (i < num)
	{
		ch_ptr[i] = ch;
		i++;
	}
	return (ptr);
}
