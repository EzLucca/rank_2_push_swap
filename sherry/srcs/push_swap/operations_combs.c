/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_combs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:26:28 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/09 12:59:18 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
	the function is for pushing a num from a stack to the other one(a to b,
	or b to a), and push it to the correct place, using rotate operation in
	both stacks.

	direction:
		1: from a to b;
		otherwise, from b to a;
*/
int	execute_rarb(t_stack **a, t_stack **b, int num, int direction)
{
	if (direction == 1)
	{
		while (*a && (*a)-> nbr != num && find_place_in_stack_b(*b, num) > 0)
			rotate_rr(a, b, 0);
		while (*a && (*a)-> nbr != num)
			rotate(a, 1, 0);
		while (find_place_in_stack_b(*b, num) > 0)
			rotate(b, 2, 0);
		push(a, b, 2, 0);
	}
	else
	{
		while (*b && (*b)-> nbr != num && find_place_in_stack_a(*a, num) > 0)
			rotate_rr(a, b, 0);
		while (*b && (*b)-> nbr != num)
			rotate(b, 2, 0);
		while (find_place_in_stack_a(*a, num) > 0)
			rotate(a, 1, 0);
		push(b, a, 1, 0);
	}
	return (-1);
}

/*
	the function is for pushing num from a stack to the other one(a to b, or b to a),
	and push it to the correct place, using rev_rotate operation in both stacks.

	direction:
		1: from a to b;
		otherwise, from b to a;
*/
int	execute_rrarrb(t_stack **a, t_stack **b, int num, int direction)
{
	if (direction == 1)
	{
		while (*a && (*a)-> nbr != num && find_place_in_stack_b(*b, num) > 0)
			rev_rotate_rrr(a, b, 0);
		while (*a && (*a)-> nbr != num)
			rev_rotate(a, 1, 0);
		while (find_place_in_stack_b(*b, num) > 0)
			rev_rotate(b, 2, 0);
		push(a, b, 2, 0);
	}
	else
	{
		while (*b && (*b)-> nbr != num && find_place_in_stack_a(*a, num) > 0)
			rev_rotate_rrr(a, b, 0);
		while (*b && (*b)-> nbr != num)
			rev_rotate(b, 2, 0);
		while (find_place_in_stack_a(*a, num) > 0)
			rev_rotate(a, 1, 0);
		push(b, a, 1, 0);
	}
	return (-1);
}

/*
	the function is for pushing num from a stack to the other one(a to b, or b to a),
	for a, and push it to the correct place, using rev_rotate operation,
	for b, using rotate operation.

	direction:
		1: from a to b;
		otherwise, from b to a;
*/
int	execute_rrarb(t_stack **a, t_stack **b, int num, int direction)
{
	if (direction == 1)
	{
		while (*a && (*a)-> nbr != num)
			rev_rotate(a, 1, 0);
		while (find_place_in_stack_b(*b, num) > 0)
			rotate(b, 2, 0);
		push(a, b, 2, 0);
	}
	else
	{
		while (*b && (*b)-> nbr != num)
			rotate(b, 2, 0);
		while (find_place_in_stack_a(*a, num) > 0)
			rev_rotate(a, 1, 0);
		push(b, a, 1, 0);
	}
	return (-1);
}

/*
	the function is for pushing num from a stack to the other one(a to b, or b to a),
	for a, and push it to the correct place, using rotate operation, for
	b, using rev_rotate operation.

	direction:
		1: from a to b;
		otherwise, from b to a;
*/
int	execute_rarrb(t_stack **a, t_stack **b, int num, int direction)
{
	if (direction == 1)
	{
		while (*a && (*a)-> nbr != num)
			rotate(a, 1, 0);
		while (find_place_in_stack_b(*b, num) > 0)
			rev_rotate(b, 2, 0);
		push(a, b, 2, 0);
	}
	else
	{
		while (*b && (*b)-> nbr != num)
			rev_rotate(b, 2, 0);
		while (find_place_in_stack_a(*a, num) > 0)
			rotate(a, 1, 0);
		push(b, a, 1, 0);
	}
	return (-1);
}
