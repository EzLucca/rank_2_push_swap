/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:45:27 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/04/10 13:46:12 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	ch = (char)c;
	while (str[i] != ch)
	{
		if (str[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (&str[i]);
}
