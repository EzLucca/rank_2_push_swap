/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:20:11 by hutzig            #+#    #+#             */
/*   Updated: 2025/06/17 14:47:33 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stack_last(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	ft_stack_size(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_stack_min(t_stack **stack)
{
	int		min;
	t_stack	*tmp;

	tmp = *stack;
	min = tmp->nb;
	while (tmp)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_stack_max(t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	tmp = *stack;
	max = tmp->nb;
	while (tmp)
	{
		if (tmp->nb > max)
			max = tmp->nb;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_stack_position(t_stack **stack, int nb)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp && tmp->nb != nb)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
