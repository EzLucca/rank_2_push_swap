/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:03:19 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:44:13 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Appends `src` to `dest` with a maximum buffer size.
 *
 * This function appends up to `size - len_dest - 1` characters from `src` 
 * to `dest`, ensuring the result is null-terminated. It returns the total 
 * length of the string that would have been created if there were enough 
 * space, which is the sum of the lengths of `dest` and `src`. 
 * If `dest` is already longer than or equal to `size`,
 * it returns `size + len_src`.
 *
 * @param dest  The destination buffer to append to.
 * @param src   The source string to append.
 * @param size  The total size of the destination buffer.
 * @return      The total length of the string that would have been created.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	if (!dest || !src)
		return (0);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	len_dest = ft_strlen(dest);
	if (len_dest >= size)
		return (size + len_src);
	i = 0;
	while (src[i] && (len_dest + i) < (size - 1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
