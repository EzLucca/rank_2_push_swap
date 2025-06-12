/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:51:33 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/09 12:15:49 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
	The function is push elements from stack_a to stack_b one by one, until only 3 elements
	left in stack_a.

	For each push, the element from stack_a should be pushed to the right postion
	in stack_b. So before pushing, we need to calculate the cost of pushing each element
	in stack_a to stack_b, to find the cheapest element which using least operations.
*/
void	sort_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int			steps;
	t_stack		*tmp;

	while (stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		tmp = *stack_a;
		steps = find_cheapest_steps_to_b(*stack_a, *stack_b);
		while (steps >= 0 && tmp)
		{
			if (steps == if_rrarrb(*stack_a, *stack_b, tmp -> nbr, 1))
				steps = execute_rrarrb(stack_a, stack_b, tmp -> nbr, 1);
			else if (steps == if_rarrb(*stack_a, *stack_b, tmp -> nbr, 1))
				steps = execute_rarrb(stack_a, stack_b, tmp -> nbr, 1);
			else if (steps == if_rrarb(*stack_a, *stack_b, tmp -> nbr, 1))
				steps = execute_rrarb(stack_a, stack_b, tmp -> nbr, 1);
			else if (steps == if_rarb(*stack_a, *stack_b, tmp -> nbr, 1))
				steps = execute_rarb(stack_a, stack_b, tmp -> nbr, 1);
			else
				tmp = tmp -> next;
		}
	}
}

/*
	Function:
	-  This function will one by one pushes all the elements in stack_a to the stack_b,
	   until only three elements are left in stack_a.
	-  While pushing, it makes sure if the stack_b is sorted. When three elements are
	   left, it calls the sort_three function to sort left over elements in stack_a.

	Steps:
	1, at the very beginning, if the size of stack a is greater than 3 and stack is not
	   sorted, then push 2 elements from stack_a to stack_b;
	2, if the size of stack_a is still more than 3 and not sorted, then call function
	   sort_till_3();
	3, if the size of the stack_a is equal or less than 3, but not sorted, then call
	   function sort_3();
	4, because of every time we will push a element to the its right postion in stack_b
		from stack_a, so at the end we will get a sorted stack_b but in descending order;
*/
t_stack	*push_sort_b(t_stack **stack_a)
{
	t_stack		*stack_b;

	stack_b = NULL;
	if (stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
		push(stack_a, &stack_b, 2, 0);
	if (stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
		push(stack_a, &stack_b, 2, 0);
	if (stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
		sort_till_3(stack_a, &stack_b);
	if (!is_sorted(*stack_a))
		sort_3(stack_a);
	return (stack_b);
}

/*
	The function pushs elements from stack_b to stack_a one by one, and following acending order.
*/
t_stack	**push_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int			steps;
	t_stack		*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		steps = find_cheapest_steps_to_a(*stack_a, *stack_b);
		while (steps >= 0 && tmp)
		{
			if (steps == if_rrarrb(*stack_a, *stack_b, tmp -> nbr, 2))
				steps = execute_rrarrb(stack_a, stack_b, tmp -> nbr, 2);
			else if (steps == if_rarb(*stack_a, *stack_b, tmp -> nbr, 2))
				steps = execute_rarb(stack_a, stack_b, tmp -> nbr, 2);
			else if (steps == if_rrarb(*stack_a, *stack_b, tmp -> nbr, 2))
				steps = execute_rrarb(stack_a, stack_b, tmp -> nbr, 2);
			else if (steps == if_rarrb(*stack_a, *stack_b, tmp -> nbr, 2))
				steps = execute_rarrb(stack_a, stack_b, tmp -> nbr, 2);
			else
				tmp = tmp -> next;
		}
	}
	return (stack_a);
}

/*
	- when this function is called, the order must be wrong. So don't need consider the stack
	  is sorted situation.
	- When the first element is the smallest, execute sa, ra.
	- when the first element is the biggest, execute ra. Then checking if the stack is sorted,
	  if not, then execute ra again,
	- in else conditions, if the min_value is the second element, then execute sa; otherwise,
	  execute rra.
*/
void	sort_3(t_stack **stack)
{
	int		min;
	int		max;

	min = min_value(*stack);
	max = max_value(*stack);
	if ((*stack)-> nbr == min)
	{
		rev_rotate(stack, 1, 0);
		swap(stack, 1, 0);
	}
	else if ((*stack)-> nbr == max)
	{
		rotate(stack, 1, 0);
		if (!is_sorted(*stack))
			swap(stack, 1, 0);
	}
	else
	{
		if (find_index(*stack, min) == 1)
			swap(stack, 1, 0);
		else
			rev_rotate(stack, 1, 0);
	}
}

/*
	If there are only 2 elements there , then just needs to simply swap stack_a.
	And finally it makes final sort in stack_a after all values pushed to stack_b,
	sorted and pushed back to stack_a. Because, even the stack_a is sorted at the end,
	the minimum number have to at the top of the stack_a. So, it simply brings the
	smallest number of the stack_a to the top.
*/
void	sort_ascending(t_stack **stack_a)
{
	t_stack		*stack_b;
	int			i;
	int			min;

	if (stack_size(*stack_a) == 2)
		swap(stack_a, 1, 0);
	else if (stack_size(*stack_a) == 3)
		sort_3(stack_a);
	else
	{
		stack_b = push_sort_b(stack_a); // get a sorted stack_b
		stack_a = push_sort_a(stack_a, &stack_b); // push elemennts from b to a.
		min = min_value(*stack_a); // find the minimum value in stack_a
		i = find_index(*stack_a, min); // find the index of the smallest number in stack_a
		// if the index of min_value is closer to the top, then rotate stack_a to bring
		// min_value to the top
		if (i < stack_size(*stack_a) / 2)
		{
			while ((*stack_a)-> nbr != min)
				rotate(stack_a, 1, 0);
		}
		// if the index of min_value is closer to the bottom, then reverse rotate stack_a to bring
		// min_value to the top
		else
		{
			while ((*stack_a)-> nbr != min)
				rev_rotate(stack_a, 1, 0);
		}
	}
}
