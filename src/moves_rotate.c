/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:11:03 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 12:20:43 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_rotate(t_stack **src)
{
	t_stack	*first;
	t_stack	*last;

	first = *src;
	last = stack_last(src);
	*src = first->next;
	first->next = NULL;
	last->next = first;
}

void	rotate_a(t_stack **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	move_rotate(stack);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	move_rotate(stack);
	ft_printf("rb\n");
}

void	rotate_r(t_stack **a, t_stack **b)
{
	if (!(*a) || !(*b) || !(*a)->next || !(*b)->next)
		return ;
	move_rotate(a);
	move_rotate(b);
	ft_printf("rr\n");
}
