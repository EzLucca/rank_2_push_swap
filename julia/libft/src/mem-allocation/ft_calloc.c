/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:13:16 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:45:35 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocate and zero-initialize array.
 * 
 * Allocates a block of memory for an array of num elements, 
 * each of them size bytes long, and initializes all its bits to zero. 
 * 
 * @note Original `calloc` typically checks if multiplying `num` and `size` 
 * 		 would result in an integer overflow. If an overflow is detected,
 * 		 function will return NULL to indicate that the memory allocation
 * 		 has failed.
 * 
 * @note Check for multiplication overflow:
 * 
 * - Casting -1 to size_t `(size_t)(-1)` is equal `SIZE_MAX`, what represents 
 *   the largest possible value for size_t and depends on the system's 
 * 	 architecture: on a 32-bit system, SIZE_MAX is 2^32 - 1, or 4294967295,
 * 	 on a 64-bit system, SIZE_MAX is 2^64 - 1, or 18446744073709551615.
 * 
 * - Check if `num` too large: `(size && num > (SIZE_MAX / size))`.
 * 
 * - Check if `size` too large: `(num && size > (SIZE_MAX / num))`.
 * 
 * - Returns NULL if overflow was detected.
 * 
 * @param num 		Number of elements to allocate.
 * @param size 		Size of each element.
 * @return void* 	On success, a pointer to the memory block allocated 
 * by the function. If the function failed to allocate the requested block 
 * of memory, a null pointer is returned.
 */
void	*ft_calloc(size_t num, size_t size)
{
	size_t	size_max;
	void	*res;

	size_max = (size_t)(-1);
	if ((size && num > (size_max / size)) || (num && size > (size_max / num)))
		return (0);
	res = malloc(num * size);
	if (!res)
		return (0);
	res = ft_memset(res, 0, num * size);
	return (res);
}
