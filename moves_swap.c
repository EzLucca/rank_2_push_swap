/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:39 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/05 11:21:39 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Functions to create
// move_sa
int	move_swap_a(t_ps *st, int print_flag)
{
	int tmp;

	if(st->height_a > 1)
	{
		if(print_flag == 1)
			ft_printf("sa\n");
		tmp = st->a[st->ac - st->height_a -1];
		st->a[st->ac - st->height_a - 1] = st->a[st->ac - st->height_a];
		st->a[st->ac - st->height_a] = tmp;
		return (1);
	}
	else
		return (-1)
}
// move_sb
int	move_swap_b(t_ps *st, int print_flag)
{
	int tmp;

	if(st->height_b > 1)
	{
		if(print_flag == 1)
			ft_printf("sb\n");
		tmp = st->b[st->ac - st->height_b -1];
		st->b[st->ac - st->height_b - 1] = st->b[st->ac - st->height_b];
		st->b[st->ac - st->height_b] = tmp;
		return (2);
	}
	else
		return (-2)
}
// move_ss
int move_swap_s(t_ps *st, int print_flag)
{
	if (move_swap_a(st, 0) + move_swap_b(st, 0) != 3)
		return (-3);
	else
	{
		if (print_flag == 1)
			ft_printf("ss\n");
		return (3);
	}
}
