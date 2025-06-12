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

t_ps	*init_stack(void)
{
	t_ps *stack = malloc(sizeof(t_ps));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return(stack);
}

void pop_stack(t_ps *stack, int value)
{
}
