/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_push_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:36:19 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/12 13:24:44 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/checker_bonus.h"

/*
	swap the top two elements in the stack.
	do nothing if there is only one or empty or null poiter.
*/
void	swap_bns(t_stack **s)
{
	t_stack		*tmp;

	if (!s || !*s || !(*s)-> next)
		return ;
	tmp = *s;
	(*s) = (*s)-> next;
	tmp -> next = (*s)-> next;
	(*s)-> next = tmp;
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
void	push_bns(t_stack **depa, t_stack **dest)
{
	t_stack		*tmp;

	if (!depa || !dest || !*depa)
		return ;
	tmp = *depa;
	*depa = (*depa)-> next;
	tmp -> next = *dest;
	*dest = tmp;
}
