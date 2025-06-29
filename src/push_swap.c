/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:35:22 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/29 15:15:07 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Entry point of the push_swap program.
 *
 * Initializes stacks A and B, parses and validates input, checks for duplicates,
 * and triggers the sorting algorithm if the stack is not already sorted.
 * If input is invalid or contains duplicates, an error message is printed
 * and the program exits safely.
 *
 * @param ac Argument count.
 * @param av Argument vector.
 * @return 0 on success or if no sorting is needed.
 */
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	create_stack(ac, av, &a);
	if (!a || duplicates_check(a))
	{
		ft_putstr_fd("Error\n", 2);
		free_exit(&a, &b);
	}
	if (!ascending_check(&a))
		sort_stack(&a, &b);
	free_exit(&a, &b);
}
