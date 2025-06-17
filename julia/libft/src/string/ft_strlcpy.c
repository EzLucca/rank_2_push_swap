/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:02:39 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:44:09 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies `src` to `dest` with a maximum buffer size.
 *
 * This function copies up to `size - 1` characters from `src` to `dest`, 
 * ensuring that `dest` is null-terminated if `size` is greater than 0. 
 * It always null-terminates the destination string if there is space. 
 * The function returns the total length of `src`.
 *
 * @param dest  The destination buffer to copy to.
 * @param src   The source string to copy.
 * @param size  The total size of the destination buffer.
 * @return      The total length of the source string.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	if (!dest || !src)
		return (0);
	src_len = 0;
	i = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
