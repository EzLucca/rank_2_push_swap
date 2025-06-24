/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:51:08 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/24 17:51:17 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while(array[i])
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
		free(array);
	}
}
