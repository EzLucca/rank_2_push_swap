/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:11:03 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/04 11:11:04 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Functions to create
//  - rotate_a
int move_rotate_a(t_ps *st, int print_flag)
{
	int tmp;
	int i;

	if(st->height_a > 0)
	{
		if(print_flag == 1)
			ft_printf("ra\n");
		tmp = st->a[st->ac - st->height_a - 1];
		i = 0;
		while (i < st->height_a - 1)
		{
			st->a[st->ac - st->height_a - 1 + i] = st->a[st->ac - st->height_a + i];
			i++;
		}
		st->a[st->ac - st->height_a - 1 + i] = tmp;
		return (6);
	}
	return (-6);
}
//  - rotate_b
int move_rotate_b(t_ps *st, int print_flag)
{
	int tmp;
	int i;

	if(st->height_b > 0)
	{
		if(print_flag == 1)
			ft_printf("rb\n");
		tmp = st->b[st->ac - st->height_b - 1];
		i = 0;
		while (i < st->height_b - 1)
		{
			st->b[st->ac - st->height_b - 1 + i] = st->b[st->ac - st->height_b + i];
			i++;
		}
		st->b[st->ac - st->height_b - 1 + i] = tmp;
		return (7);
	}
	return (-7);
}
//  - rotate_r
int	move_rotate_r(t_ps *st, int print_flag)
{
	if (move_rotate_a(st, 0) + move_rotate_b(st, 0) != 13)
		return (-13);
	else
	{
		if(print_flag == 1)
			ft_printf("rr\n");
		return (13);
	}
}
