/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:35:22 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/26 18:00:24 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*st_a;
	t_stack	*st_b;

	if (ac < 2)
		return (0);
	st_a = NULL;
	st_b = NULL;
	create_stack(ac, av, &st_a);
	if (!st_a || duplicates_check(st_a))
	{
		ft_putstr_fd("Error\n", 2);
		free_exit(&st_a, &st_b);
	}
	if (!ascending_check(&st_a))
		sort_stack(&st_a, &st_b);
	free_exit(&st_a, &st_b);
}
