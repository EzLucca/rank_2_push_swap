/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:30:51 by hutzig            #+#    #+#             */
/*   Updated: 2025/06/17 14:50:15 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This function transfers of the top element from one stack to another. */
static void	push_elements(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

/* pa: take the first element of stack B and push it at the top of stack A 
 * do nothing if B is empty */
void	pa(t_stack **b, t_stack **a)
{
	if (!(*b))
		return ;
	push_elements(b, a);
	write(1, "pa\n", 3);
}

/* pb: take the first element of stack A and push it at the top of stack B
 * do nothing if A is empty */
void	pb(t_stack **a, t_stack **b)
{
	if (!(*a))
		return ;
	push_elements(a, b);
	write(1, "pb\n", 3);
}
