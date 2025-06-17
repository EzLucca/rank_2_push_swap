/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:16:01 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/06 12:51:03 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Remove leading and trailing set of characters from strings.
 * 
 * Allocates (with malloc(3)) and returns a copy of 
 * `s1` with the characters specified in `set` removed
 * from the beginning and the end of the string.
 * 
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return char* The trimmed string.  NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*res;

	if (!s1 || !set)
		return (0);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	start = s1;
	if (*s1 == '\0')
		return ((char *) ft_calloc(1, sizeof(char)));
	end = s1 + ft_strlen(s1) - 1;
	while (start < end && ft_strchr(set, *end))
		end--;
	res = (char *) malloc((end - start + 2) * sizeof(char));
	if (!res)
		return (0);
	ft_memcpy(res, start, end - start + 1);
	res[end - start + 1] = '\0';
	return (res);
}
