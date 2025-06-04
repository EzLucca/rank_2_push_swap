/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:39 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/04 11:10:40 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Functions to create

static void swap(t_list **stack)
{
	t_list *tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = tmp;
}
//  - swap_a
void sa(t_list *a)
{
	swap(a);
}
//  - swap_b
void sb(t_list *b)
{
	swap(b);
}
//  - swap_s
void ss(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
}
