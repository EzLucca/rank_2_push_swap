/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:55 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 12:20:24 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack **src)
{
	t_stack	*first;
	t_stack	*last;

	first = *src;
	last = NULL;
	while (first->next)
	{
		last = first;
		first = first->next;
	}
	last->next = NULL;
	first->next = *src;
	*src = first;
}

void	reverse_rotate_a(t_stack **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	reverse_rotate_r(t_stack **a, t_stack **b)
{
	if (!(*a) || !(*b) || !(*a)->next || !(*b)->next)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
