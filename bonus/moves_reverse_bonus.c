/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:55 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 16:41:11 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Moves the last element of the stack to the top.
 *
 * This function performs the reverse rotation on a single stack.
 * It moves the last node to the front, shifting all others down.
 *
 * @param src Pointer to the stack to reverse rotate.
 */
void	reverse_rotate(t_stack **src)
{
	t_stack	*first;
	t_stack	*last;

	first = *src;
	last = NULL;
	while (first->next)
	{
		last = first;
		first = first->next;
	}
	last->next = NULL;
	first->next = *src;
	*src = first;
}

/**
 * @brief Performs the 'rra' operation: reverse rotate stack A.
 *
 * Moves the last element of stack A to the top and prints "rra".
 * If the stack has fewer than 2 elements, the operation is ignored.
 *
 * @param stack Pointer to stack A.
 */
void	reverse_rotate_a(t_stack **st)
{
	if (!(*st) || !(*st)->next)
		return ;
	reverse_rotate(st);
}

/**
 * @brief Performs the 'rrb' operation: reverse rotate stack B.
 *
 * Moves the last element of stack B to the top and prints "rrb".
 * If the stack has fewer than 2 elements, the operation is ignored.
 *
 * @param stack Pointer to stack B.
 */
void	reverse_rotate_b(t_stack **st)
{
	if (!(*st) || !(*st)->next)
		return ;
	reverse_rotate(st);
}

/**
 * @brief Performs the 'rrr' operation: reverse rotate both stacks A and B.
 *
 * Moves the last element of both stacks to the top simultaneously,
 * and prints "rrr". If either stack has fewer than 2 elements,
 * the operation is ignored.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	reverse_rotate_r(t_stack **st_a, t_stack **st_b)
{
	if (!(*st_a) || !(*st_b) || !(*st_a)->next || !(*st_b)->next)
		return ;
	reverse_rotate(st_a);
	reverse_rotate(st_b);
}
