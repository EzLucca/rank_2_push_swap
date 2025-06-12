/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stacklist2_find.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:25:43 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/09 12:55:52 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// find the minimum value in a stack
int	min_value(t_stack *stack)
{
	int			min;
	t_stack		*tmp;

	tmp = stack -> next;
	min = stack -> nbr;
	while (tmp)
	{
		if (min > tmp -> nbr)
			min = tmp -> nbr;
		tmp = tmp -> next;
	}
	return (min);
}

int	max_value(t_stack *stack)
{
	int			max;
	t_stack		*tmp;

	tmp = stack -> next;
	max = stack -> nbr;
	while (tmp)
	{
		if (max < tmp -> nbr)
			max = tmp -> nbr;
		tmp = tmp -> next;
	}
	return (max);
}

int	find_index(t_stack *stack, int value)
{
	int			index;

	index = 0;
	while (stack && (stack -> nbr) != value)
	{
		stack = stack -> next;
		index++;
	}
	return (index);
}

/*
	The function is using to fine the right place in stack_b for nbr_push, if we want
	push nbr_push into the stack_b.(In stack_b, the order is ascending.)

	Parameters:
		stack_a: the stack where we need find the place in;
		nbr_push: the number we want to push to stack;

	Return value:
		the index of the right place;

	Steps:
		- if the nbr_push is greater than the biggest number or smaller than the smallest
		  number in the stack, then the right place is at the top of biggest number.
		- else  the right place should be between num_up and num_down, that
		"num_up > nbr_push > num_down".
		  	-- we can loop the stack the find the right place, but the loop will miss one
			   condition, that is when num_a is the first number and num_b is the last
			   number, so we need to use a seperate "if" for checking this condition.
*/
int	find_place_in_stack_b(t_stack *b, int num)
{
	int		index;
	t_stack	*tmp;

	index = 1;
	if (num > (b -> nbr) && num < (stack_last(b)-> nbr))
		index = 0;
	else if (num > max_value(b) || num < min_value(b))
		index = find_index(b, max_value(b));
	else
	{
		tmp = b-> next;
		while ((tmp -> next) && (num > (b -> nbr) || num < (tmp -> nbr)))
		{
			b = b -> next;
			tmp = tmp -> next;
			index++;
		}
	}
	return (index);
}

/*
	The function is using to fine the right place in stack_a for nbr_push, if we want
	push nbr_push into the stack_a.(In stack_a, the order is descending.)

	Parameters:
		stack_a: the stack where we need find the place in;
		nbr_push: the number we want to push to stack;

	Return value:
		the index of the right place;

	Steps:
		- if the nbr_push is greater than the biggest number or smaller than the smallest
		  number in the stack, then the right place is at the top of smallest number.
		- else, the right place should be between num_up and num_down,
		 that num_up < nbr_push < num_down.
		  	-- we can loop the stack the find the right place, but the loop will miss one
			   condition, that is when num_a is the first number and num_b is the last
			   number, so we need to use a seperate "if" for checking this condition.
*/
int	find_place_in_stack_a(t_stack *a, int num)
{
	int		index;
	t_stack	*tmp;

	index = 1;
	if (num < (a -> nbr) && num > (stack_last(a)-> nbr))
		index = 0;
	else if (num > max_value(a) || num < min_value(a))
		index = find_index(a, min_value(a));
	else
	{
		tmp = a-> next;
		while ((tmp -> next) && (num < (a -> nbr) || num > (tmp -> nbr)))
		{
			a = a -> next;
			tmp = tmp -> next;
			index++;
		}
	}
	return (index);
}
