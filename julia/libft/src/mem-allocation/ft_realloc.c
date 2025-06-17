/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:40:49 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/06 12:43:45 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Reallocates memory, keeping the old data.
 * 
 * This function resizes the memory block pointed to by `ptr` to `new_size`,
 * copying the original data up to the smaller of `old_size` and `new_size`. 
 * 
 * @note
 * 	- If `ptr` is `NULL`, it acts like `malloc`. 
 * 	- If `new_size` is 0, it doesn't frees `ptr` and just returns `NULL`.
 * 
 * @param ptr Pointer to the memory to resize. 
 * 			  If `NULL`, it allocates new memory.
 * @param old_size Size of the original memory block.
 * @param new_size New size for the memory block.
 * @return void* Pointer to the reallocated memory, or `NULL` if it fails.
 */

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*res;
	size_t	size;

	if (!ptr)
		return (malloc(new_size));
	if (0 == new_size)
		return (NULL);
	res = (char *) malloc(new_size);
	if (!res)
		return (NULL);
	size = old_size;
	if (size > new_size)
		size = new_size;
	ft_memcpy(res, ptr, size);
	free(ptr);
	return ((void *)res);
}
