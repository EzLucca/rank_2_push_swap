/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:34:43 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/25 10:22:16 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_st	*stack_last(t_st **st)
{
	t_st	*tmp;

	tmp = *st;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	stack_size(t_st **st)
{
	int		i;
	t_st	*tmp;

	i = 0;
	tmp = *st;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	stack_max(t_st **st)
{
	int		max;
	t_st	*tmp;

	tmp = *st;
	max = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr > max)
			max = tmp->nbr;
		tmp = tmp->next;
	}
	return (max);
}

int	stack_min(t_st **st)
{
	int		min;
	t_st	*tmp;

	tmp = *st;
	min = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	return (min);
}

int	stack_position(t_st **st, int nbr)
{
	int		i;
	t_st	*tmp;

	i = 0;
	tmp = *st;
	while (tmp && tmp->nbr != nbr)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
