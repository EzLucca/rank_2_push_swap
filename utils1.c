/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:09:09 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/16 12:53:24 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_ps *st)
{
	if(st->a)
	{
		free(st->a);
		st->a = NULL;
	}
	if(st->b)
	{
		free(st->b);
		st->b = NULL;
	}
}

void	free_array(void ***array)
{
	int	i;

	i = 0;
	if (array == NULL || *array == NULL)
		return ;
	while ((*array)[i])
	{
		free((*array)[i]);
		(*array)[i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
}
