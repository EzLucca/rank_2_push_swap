/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:48:19 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/12 13:29:01 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/checker_bonus.h"

/*
	Shift up all elements of a stack by 1. The first element becomes the last one.
	If there is less than 2 elements, then return.
*/
void	rotate_bns(t_stack **s)
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
}

// rotate stack_a and stack_b at same time.
void	rotate_rr_bns(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	rotate_bns(stack_a);
	rotate_bns(stack_b);
}

/*
	Shift down all elements of a stack by 1. The last element becomes the first one.
	If there is less than 2 elements, then return.
*/
void	rev_rotate_bns(t_stack **s)
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
}

void	rev_rotate_rrr_bns(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	rev_rotate_bns(stack_a);
	rev_rotate_bns(stack_b);
}
