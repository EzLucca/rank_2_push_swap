/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:11:27 by ipersids          #+#    #+#             */
/*   Updated: 2024/11/01 18:24:10 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate the first occurrence of a substring within a string.
 * 
 * The function searches for the `little` in the `big` but only within the first 
 * `len` characters of big. 
 * 
 * NOTE: Comparing with original implementation the function ft_strnstr 
 * is adopted handling of NULL arguments `big` or `little` and returns NULL. 
 * In these cases original strnstr might cause the segmentation fault.
 * 
 * @param big 		The main string in which the search is performed.
 * @param little 	The substring you are looking for.
 * @param len 		The maximum number of characters to be searched in big.
 * @return char* 	Returns a pointer to the first occurrence of little in big
 * within the first len characters. If little is an empty string, it returns 
 * a pointer to the beginning of big. If little is not found returns NULL.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	if (*little == '\0')
		return ((char *)(big));
	little_len = ft_strlen(little);
	i = 0;
	while (big[i] && (len - i) >= little_len)
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
