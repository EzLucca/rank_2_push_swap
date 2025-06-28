/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:48 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 16:17:15 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Moves the top element from the source stack to the destination stack.
 *
 * This function detaches the top node from `src` and places it at the top of
 * `dst`. It does not print anything — used internally by `push_a` and `push_b`.
 *
 * @param src Pointer to the source stack.
 * @param dst Pointer to the destination stack.
 */
void	move_push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

/**
 * @brief Performs the 'pa' operation: push top element from stack B to stack A.
 *
 * Moves the top node of stack B to the top of stack A and prints "pa".
 * If the source stack is empty, the operation is ignored.
 *
 * @param src Pointer to stack B (source).
 * @param dst Pointer to stack A (destination).
 */
void	push_a(t_stack **src, t_stack **dst)
{
	if (!(*src))
		return ;
	move_push(src, dst);
	ft_printf("pa\n");
}

/**
 * @brief Performs the 'pb' operation: push top element from stack A to stack B.
 *
 * Moves the top node of stack A to the top of stack B and prints "pb".
 * If the source stack is empty, the operation is ignored.
 *
 * @param src Pointer to stack A (source).
 * @param dst Pointer to stack B (destination).
 */
void	push_b(t_stack **src, t_stack **dst)
{
	if (!(*src))
		return ;
	move_push(src, dst);
	ft_printf("pb\n");
}
