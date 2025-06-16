/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:38:27 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/28 10:53:04 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algo_large_case(t_int **lst1, t_int **lst2, int num_max, int i);

// the function uses the algorithm to sort the stack
// containing large number of arguments

void	algo_large(t_int **lst1, t_int **lst2)
{
	int		num_max;
	int		bits_count;
	int		i;

	bits_count = 0;
	num_max = ft_lstsize_int(*lst1) - 1;
	while ((num_max >> bits_count) != 0)
		bits_count++;
	i = 0;
	while (i < bits_count)
	{
		algo_large_case(lst1, lst2, num_max, i);
		while (ft_lstsize_int(*lst2))
			push_a(lst1, lst2);
		++i;
	}
}

static void	algo_large_case(t_int **lst1, t_int **lst2, int num_max, int i)
{
	int		j;

	j = 0;
	while (j < num_max +1)
	{
		if ((((*lst1)->simple >> i) & 1) == 1)
			rotate_a(lst1);
		else
			push_b(lst1, lst2);
		++j;
	}
}
