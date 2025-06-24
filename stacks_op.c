/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:34:43 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/24 18:13:33 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_stack	*stack_last(t_stack **st)
{
	t_stack	*tmp;

	if (!st || !(*st))
		return (NULL);
	tmp = *st;
	while(tmp->next)
		tmp = tmp->next;
	return(tmp);
}

int	stack_size(t_stack **st)
{
	int		i;
	t_stack	*tmp;

	if (!st || !(*st))
		return (1);
	i = 0;
	tmp = *st;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	stack_max(t_stack **st)
{
	int	max;
	t_stack	*tmp;

	if (!st || !(*st))
		return (1);
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

int	stack_min(t_stack **st)
{
	int	min;
	t_stack	*tmp;

	if (!st || !(*st))
		return (1);
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

int	stack_position(t_stack **st, int nbr)
{
	int		i;
	t_stack	*tmp;

	if (!st || !(*st))
		return (1);
	i = 0;
	tmp = *st;
	while(tmp && tmp->nbr != nbr)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
