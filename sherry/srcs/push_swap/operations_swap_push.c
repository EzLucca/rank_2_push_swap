/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:36:19 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/09 12:11:11 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
	swap the top two elements in the stack.
	do nothing if there is only one or empty or null poiter.

	diretion;
		direction = 1, represents output "sa";
		direction = 2, represents output "sb";

	if_print:
		if_print = 0, output;
		if_print is not 0, don't output.
*/
void	swap(t_stack **s, int direction, int if_print)
{
	t_stack		*tmp;

	if (!s || !*s || !(*s)-> next)
		return ;
	tmp = *s;
	(*s) = (*s)-> next;
	tmp -> next = (*s)-> next;
	(*s)-> next = tmp;
	if (if_print == 0)
	{
		if (direction == 1)
			write(1, "sa\n", 3);
		else if (direction == 2)
			write(1, "sb\n", 3);
	}
}

/*
	push the first element from stack depa(departure) to the top of stack dest(destination)
	do nothing if depa or dest is null pointer or if depa is empty.

	diretion;
		direction = 1, represents output "pa", meaning pushing element from b to a;
		direction = 2, represents output "pb", meaning pushing element from a to b;

	if_print:
		if_print = 0, output;
		if_print is not 0, don't output.
*/
void	push(t_stack **depa, t_stack **dest, int direction, int if_print)
{
	t_stack		*tmp;

	if (!depa || !dest || !*depa)
		return ;
	tmp = *depa;
	*depa = (*depa)-> next;
	tmp -> next = *dest;
	*dest = tmp;
	if (if_print == 0)
	{
		if (direction == 1)
			write(1, "pa\n", 3);
		else if (direction == 2)
			write(1, "pb\n", 3);
	}
}
