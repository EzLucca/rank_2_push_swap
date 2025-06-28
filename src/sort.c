/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:40:26 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 16:34:29 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Sorts a stack with more than 3 elements using a chunk-based strategy.
 *
 * Pushes a couple of elements to stack B, sorts the remaining in A,
 * and gradually reinserts elements from B to A in the correct position.
 * Finally, rotates A to ensure the smallest element is at the top.
 *
 * @param a Pointer to stack A (source).
 * @param b Pointer to stack B (temporary storage).
 */
void	sort_big(t_stack **a, t_stack **b)
{
	int	i;

	i = 2;
	while (stack_size(a) > 3 && i--)
		push_b(a, b);
	if (stack_size (a) > 3)
		a_to_b(a, b);
	if (!ascending_check(a))
		sort_three(a);
	b_to_a(a, b);
	if (!ascending_check(a))
	{
		i = stack_position(a, stack_min(a));
		if (i <= stack_size(a) / 2)
		{
			while ((*a)->nbr != stack_min(a))
				rotate_a(a);
		}
		else
		{
			while ((*a)->nbr != stack_min(a))
				reverse_rotate_a(a);
		}
	}
}

/**
 * @brief Sorts a stack of exactly 3 elements in ascending order.
 *
 * Applies a minimal combination of `ra`, `rra`, and `sa` to bring
 * the stack into sorted order.
 *
 * @param a Pointer to stack A.
 */
void	sort_three(t_stack **a)
{
	if ((*a)->nbr == stack_max(a))
		rotate_a(a);
	else if ((*a)->next->nbr == stack_max(a))
		reverse_rotate_a(a);
	if ((*a)->nbr > (*a)->next->nbr)
		swap_a(a);
}

/**
 * @brief Determines and executes the appropriate sorting strategy for stack A.
 *
 * - For 2 elements: swaps if necessary.
 * - For 3 elements: uses `sort_three`.
 * - For more: uses the full stack sorting strategy (`sort_big`).
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B (used during sorting if needed).
 */
void	sort_stack(t_stack **a, t_stack **b)
{
	if (stack_size(a) == 2)
		swap_a(a);
	else if (stack_size(a) == 3)
		sort_three(a);
	else
		sort_big(a, b);
}
