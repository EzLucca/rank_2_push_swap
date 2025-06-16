/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:00:58 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/09 13:50:52 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_char_array(char **array)
{
	int	len;
	int	i;

	len = 0;
	while (array[len])
		len++;
	i = 0;
	while (i < len)
		ft_free(array[i++]);
	ft_free(array);
}
