/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_caculate_steps_assit.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:15:25 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/09 13:00:21 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
	the fucntion caculates the steps if we push "num" to a(or b)
	only using rotate operation(rarb).

	num: the number we want to push;
	direction:
		1: from a to b;
		non 1 value: from b to a;
*/
int	if_rarb(t_stack *a, t_stack *b, int num, int direction)
{
	int		index_a;
	int		index_b;

	if (direction == 1)
	{
		index_a = find_index(a, num);
		index_b = find_place_in_stack_b(b, num);
	}
	else
	{
		index_a = find_place_in_stack_a(a, num);
		index_b = find_index(b, num);
	}
	if (index_a > index_b)
		return (index_a);
	else
		return (index_b);
}

/*
	the fucntion caculates the steps if we push "num" to a(or b)
	only using rev_rotate operation(rrarrb).

	num: the number we want to push;
	direction:
		1: from a to b;
		non 1 value: from b to a;
*/
int	if_rrarrb(t_stack *a, t_stack *b, int num, int direction)
{
	int		index_a;
	int		index_b;
	int		steps_a;
	int		steps_b;

	if (direction == 1)
	{
		index_a = find_index(a, num);
		index_b = find_place_in_stack_b(b, num);
	}
	else
	{
		index_a = find_place_in_stack_a(a, num);
		index_b = find_index(b, num);
	}
	steps_a = stack_size(a) - index_a;
	steps_b = stack_size(b) - index_b;
	if (steps_a > steps_b)
		return (steps_a);
	else
		return (steps_b);
}

/*
	the fucntion caculates the steps if we push "num" to a(or b)
	for a, we use rev_rotate operation;
	for b, we use rotate operation.

	num: the number we want to push;
	direction:
		1: from a to b;
		non 1 value: from b to a;
*/
int	if_rrarb(t_stack *a, t_stack *b, int num, int direction)
{
	int		index_a;
	int		index_b;
	int		steps_a;

	if (direction == 1)
	{
		index_a = find_index(a, num);
		index_b = find_place_in_stack_b(b, num);
	}
	else
	{
		index_a = find_place_in_stack_a(a, num);
		index_b = find_index(b, num);
	}
	steps_a = stack_size(a) - index_a;
	return (steps_a + index_b);
}

/*
	the fucntion caculates the steps if we push "num" to a(or b)
	for a, we use rotate operation;
	for b, we use rev_rotate operation.

	num: the number we want to push;
	direction:
		1: from a to b;
		non 1 value: from b to a;
*/
int	if_rarrb(t_stack *a, t_stack *b, int num, int direction)
{
	int		index_a;
	int		index_b;
	int		steps_b;

	if (direction == 1)
	{
		index_a = find_index(a, num);
		index_b = find_place_in_stack_b(b, num);
	}
	else
	{
		index_a = find_place_in_stack_a(a, num);
		index_b = find_index(b, num);
	}
	steps_b = stack_size(b) - index_b;
	return (steps_b + index_a);
}
