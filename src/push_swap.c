/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:57:34 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/30 13:57:35 by edlucca          ###   ########.fr       */
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
		exit_failure(&a, &b);
	if (!ascending_check(&a))
		sort_stack(&a, &b);
	exit_success(&a, &b);
}
