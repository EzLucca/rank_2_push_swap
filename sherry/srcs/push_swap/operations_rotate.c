/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:48:19 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/09 12:09:37 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
	Shift up all elements of a stack by 1. The first element becomes the last one.
	If there is less than 2 elements, then return.

	direction;
		direction = 1, represents output "ra";
		direction = 2, represents output "rb";

	if_print:
		if_print = 0, output;
		if_print is not 0, don't output.
*/
void	rotate(t_stack **s, char direction, int if_print)
{
	t_stack		*tmp;

	if (!s || !*s || !(*s)-> next)
		return ;
	tmp = *s;
	while ((*s)-> next)
		*s = (*s)-> next;
	(*s)-> next = tmp;
	*s = tmp -> next;
	tmp -> next = 0;
	if (if_print == 0)
	{
		if (direction == 1)
			write(1, "ra\n", 3);
		else if (direction == 2)
			write(1, "rb\n", 3);
	}
}

// rotate stack_a and stack_b at same time.
void	rotate_rr(t_stack **stack_a, t_stack **stack_b, int if_print)
{
	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	rotate(stack_a, 1, 1);
	rotate(stack_b, 2, 1);
	if (if_print == 0)
		write(1, "rr\n", 3);
}

/*
	Shift down all elements of a stack by 1. The last element becomes the first one.
	If there is less than 2 elements, then return.

	direction;
		direction = 1, represents output "rra";
		direction = 2, represents output "rrb";

	if_print:
		if_print = 0, output;
		if_print is not 0, don't output.
*/
void	rev_rotate(t_stack **s, char direction, int if_print)
{
	t_stack		*tmp;
	int			i;

	if (!s || !*s || !(*s)-> next)
		return ;
	tmp = *s;
	i = 0;
	while ((*s)-> next)
	{
		*s = (*s)-> next;
		i++;
	}
	(*s)-> next = tmp;
	while (i-- > 1)
		tmp = tmp -> next;
	tmp -> next = NULL;
	if (if_print == 0)
	{
		if (direction == 1)
			write(1, "rra\n", 4);
		else if (direction == 2)
			write(1, "rrb\n", 4);
	}
}

void	rev_rotate_rrr(t_stack **stack_a, t_stack **stack_b, int if_print)
{
	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	rev_rotate(stack_a, 1, 1);
	rev_rotate(stack_b, 2, 1);
	if (if_print == 0)
		write(1, "rrr\n", 4);
}
