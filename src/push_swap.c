/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:35:22 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 12:36:48 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static void print_stack(t_stack *stack, char *name)
// {
//     ft_printf("Stack %s: ", name);
//     while (stack)
//     {
//         ft_printf("%d ", stack->nbr);
//         stack = stack->next;
//     }
//     ft_printf("\n");
// }

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
	// print_stack(a, "A");
	// print_stack(b, "B");
	free_exit(&a, &b);
}
