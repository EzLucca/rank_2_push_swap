/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:15:20 by ipersids          #+#    #+#             */
/*   Updated: 2024/10/30 14:46:55 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates memory with `malloc` and returns a new concatenated string.
 * 
 * @param s1 the prefix string
 * @param s2 the suffix string
 * @return char* the new string. NULL if allocation fails or s1, or s2 points
 *               NULL.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!res)
		return (0);
	ft_memcpy(res, s1, s1_len);
	ft_memcpy(&(res[s1_len]), s2, s2_len);
	res[s1_len + s2_len] = '\0';
	return (res);
}
