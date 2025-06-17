/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:14:40 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:46:37 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and returns a substring from the string `s`.
 * 
 * This function allocates memory and returns a substring from the provided 
 * string `s`. The substring starts at the index `start` 
 * and spans up to `len` characters. If the allocation fails, 
 * the function returns NULL.
 * 
 * Special cases:
 * 
 * 1) If `s` is a NULL pointer, the function returns NULL.
 * 
 * 2) if `s` is empty or the `len` of the substring is 0, 
 * 	  returns new allocated empty substring or 0 (allocation fails).
 * 
 * 3) If the `start` index is beyond the length of the string (start >= s_len),
 * 	  returns new allocated empty substring or 0 (allocation fails).
 * 
 * 4) If the substring extends beyond the original string, the function 
 *    allocates and returns a substring from start 
 * 	  until the end of the original string.
 * 
 * @param s the original string from which the substring will be created.
 * @param start the starting index in `s` where the substring will begin.
 * @param len the maximum number of characters to be included in the substring.
 * @return char* A pointer to the newly created substring, 
 * 				 or NULL if memory allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (*s == '\0' || len == 0 || start >= s_len)
		return (ft_strdup(""));
	if ((start + len) > s_len)
		len = s_len - start;
	res = (char *) malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < len)
		res[i++] = s[start++];
	res[len] = '\0';
	return (res);
}
