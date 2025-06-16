/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_phase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:06:43 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/23 10:30:58 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	first_phase_push_to_b(t_list **a, t_list **b, int mid_value_a)
{
	int	size_b;

	push(a, b, "pb\n");
	size_b = size_list(*b);
	if ((*b)->data < find_mid_value(*b, size_b) && (*b)->next)
	{
		if ((*a)->data > mid_value_a)
			double_rotate(a, b);
		else
			rotate(b, "rb\n");
	}
}

static void	shortest_path_first_phase(t_list **a, t_list **b, int mid, int size)
{
	long	*array;
	int		top;
	int		bottom;
	int		i;

	i = 0;
	top = 0;
	bottom = 0;
	array = transfer_into_array(*a, size);
	while (array[i++] >= mid)
		top++;
	while (array[--size] >= mid)
		bottom++;
	if (top <= bottom)
		rotate_some_a(a, top, "ra\n");
	else
		reverse_rotate_some_a(a, bottom, "rra\n");
	free(array);
	array = NULL;
	first_phase_push_to_b(a, b, mid);
}

void	first_phase_sort(t_list **a, t_list **b)
{
	int	size_a;
	int	chunck_size;
	int	mid_value;
	int	half_stack;

	size_a = size_list(*a);
	while (size_a > 3)
	{
		chunck_size = 0;
		mid_value = find_mid_value(*a, size_a);
		half_stack = size_a / 2;
		while (half_stack--)
		{
			if ((*a)->data < mid_value)
				first_phase_push_to_b(a, b, mid_value);
			else
				shortest_path_first_phase(a, b, mid_value,
					size_a - chunck_size);
			chunck_size++;
		}
		size_a = size_list(*a);
	}
	sorting_three_numbers(a);
	second_phase_sorting(a, b);
}
