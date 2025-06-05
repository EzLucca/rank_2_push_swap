/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:59:16 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/05 11:11:33 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack *stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return(stack);
}

void pop_stack(t_stack *stack, int value)
{
	t_node *new = malloc(sizeof(t_node));
	new->value = value;
	new->next = stack->top;
	new->prev = NULL;
	if(stack->top)
		stack->top->prev = new;
	stack->top = new;
	stack->size++;
}
