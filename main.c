/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudocode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:15:21 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/16 17:11:32 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	bool	split;

	if (ac < 2)
		return (0);
	split = false;
	if (ac == 2)
		split = true;
	av = input_validation(av, split);
	parse_av(av);
	push_swap(av, &stack);
	if (split == true)
		free_arrays(av);
	free_stack(&stack);
	return (0);
}
