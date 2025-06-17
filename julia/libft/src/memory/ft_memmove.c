/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:01:52 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:43:54 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Move block of memory.
 * 
 * @param dest 	pointer for destination array where the content is to be copied.
 * @param src 	pointer for source of data to be copied.
 * @param num 	number of bytes to be copied.
 * 
 * @return void* Returns a pointer to the destination.
 */
void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = (char *)dest;
	s = (const char *)src;
	if (d < s)
	{
		while (i < num)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (num-- > 0)
			d[num] = s[num];
	}
	return (dest);
}
