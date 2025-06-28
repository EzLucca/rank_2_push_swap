/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:39 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 16:43:05 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Swaps the first two elements of a stack.
 *
 * Performs the basic swap logic: the first two nodes in the stack are 
 * exchanged.
 * Used internally by the swap operations.
 *
 * @param src Pointer to the stack.
 */
void	move_swap(t_stack **src)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = (*src)->next;
	(*src)->next = tmp;
}

/**
 * @brief Performs the 'sa' operation: swap the first two elements of stack A.
 *
 * If stack A has at least two elements, swaps them and prints "sa".
 * Otherwise, the operation is ignored.
 *
 * @param stack Pointer to stack A.
 */
void	swap_a(t_stack **st)
{
	if (!(*st) || (*st)->next == NULL)
		return ;
	move_swap(st);
}

/**
 * @brief Performs the 'sb' operation: swap the first two elements of stack B.
 *
 * If stack B has at least two elements, swaps them and prints "sb".
 * Otherwise, the operation is ignored.
 *
 * @param stack Pointer to stack B.
 */
void	swap_b(t_stack **st)
{
	if (!(*st) || (*st)->next == NULL)
		return ;
	move_swap(st);
}

/**
 * @brief Performs the 'ss' operation: swap the first two elements of both 
 * stacks.
 *
 * Swaps the top two elements of both stack A and stack B simultaneously,
 * and prints "ss". The operation is only performed if both stacks have at
 * least two elements.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	swap_s(t_stack **st_a, t_stack **st_b)
{
	if (!(*st_a) || !(*st_b) || !(*st_a)->next || !(*st_b)->next)
		return ;
	move_swap(st_a);
	move_swap(st_b);
}
