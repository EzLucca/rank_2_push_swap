/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:27:52 by hutzig            #+#    #+#             */
/*   Updated: 2025/06/17 14:50:48 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This function swaps the first two elements of the given stack.  */
static void	swap_first_elements(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

/* sa: swap the first two elements of stack A
 * do nothing if there is only one element or if A is empty. */
void	sa(t_stack **a)
{
	if (!(*a) || (*a)->next == NULL)
		return ;
	swap_first_elements(a);
	write(1, "sa\n", 3);
}

/* sb: swap the first two elements of stack B
 * do nothing if there is only one element of if B is empty. */
void	sb(t_stack **b)
{
	if (!(*b) || (*b)->next == NULL)
		return ;
	swap_first_elements(b);
	write(1, "sb\n", 3);
}

/* ss: sa && sb at the same time. */
void	ss(t_stack **a, t_stack **b)
{
	if (!(*a) || !(*b) || !(*a)->next || !(*b)->next)
		return ;
	swap_first_elements(a);
	swap_first_elements(b);
	write(1, "ss\n", 3);
}
