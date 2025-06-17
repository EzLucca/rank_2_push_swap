/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:39:13 by hutzig            #+#    #+#             */
/*   Updated: 2025/06/17 14:50:24 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This function shifts down all the elements by 1, last becomes the first. */
static void	shift_down_elements(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second_last;

	first = *stack;
	second_last = NULL;
	while (first->next)
	{
		second_last = first;
		first = first->next;
	}
	second_last->next = NULL;
	first->next = *stack;
	*stack = first;
}

/* rra: shift down all elements of stack A by 1. */
void	rra(t_stack **a)
{
	if (!(*a) || !(*a)->next)
		return ;
	shift_down_elements(a);
	write(1, "rra\n", 4);
}

/* rrb: shift down all elements of stack B by 1. */
void	rrb(t_stack **b)
{
	if (!(*b) || !(*b)->next)
		return ;
	shift_down_elements(b);
	write(1, "rrb\n", 4);
}

/* rrr: rra & rrb at the same time. */
void	rrr(t_stack **a, t_stack **b)
{
	if (!(*a) || !(*b) || !(*a)->next || !(*b)->next)
		return ;
	shift_down_elements(a);
	shift_down_elements(b);
	write(1, "rrr\n", 4);
}
