/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:39 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/05 11:21:39 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Functions to create
static void swap(t_stack *stack)
{
	if(stack->size < 2)
		return ;
	t_node *first = stack->top;
	t_node *second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	stack->top = second;
}

void	sa(t_stack **a, bool checker)
{
	swap(a);

}
void	sb(t_stack **a, bool checker)
{
	swap(b);

}
void	ss(t_stack **a, bool checker)
{
	swap(a);
	swap(b);

}
