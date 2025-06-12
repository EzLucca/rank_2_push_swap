/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:48 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/04 11:10:49 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Functions to create
//  - push_a
int move_push_a(t_ps *st, int print_flag)
{
	if(st->height_b > 0)
	{
		if (print_flag == 1)
			ft_printf("pa\n");
		st->a[st->ac - st->height_a - 2] = st->b[st->ac - st->height_b - 1];
		st->height_b--;
		st->height_a++;
		return (4);
	}
	return (-4);
}

//  - push_b
int move_push_b(t_ps *st, int print_flag)
{
	if(st->height_a > 0)
	{
		if (print_flag == 1)
			ft_printf("pb\n");
		st->b[st->ac - st->height_b - 2] = st->a[st->ac - st->height_a - 1];
		st->height_a--;
		st->height_b++;
		return (5);
	}
	return (-5);
}
