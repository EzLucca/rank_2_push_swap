/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:55 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/04 11:10:56 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Functions to create
//  - reverse_a
int move_reverse_rotate_a(t_ps *st, int print_flag)
{
	int	tmp;
	int	i;

	if(st->height_a > 0)
	{
		if(print_flag == 1)
			ft_printf("rra\n");
		tmp = st->a[st->ac - 2];
		i = 0;
		while(i < st->height_a - 1)
		{
			st->a[st->ac - 2 -i] = st->a[st->ac -3 - i];
			i++;
		}
		st->a[st->ac - 2 - i] = tmp;
		return (8);
	}
	return (-8);
}
//  - reverse_b
int move_reverse_rotate_b(t_ps *st, int print_flag)
{
	int	tmp;
	int	i;

	if(st->height_b > 0)
	{
		if(print_flag == 1)
			ft_printf("rrb\n");
		tmp = st->b[st->ac - 2];
		i = 0;
		while(i < st->height_b - 1)
		{
			st->b[st->ac - 2 -i] = st->b[st->ac -3 - i];
			i++;
		}
		st->b[st->ac - 2 - i] = tmp;
		return (9);
	}
	return (-9);
}
//  - reverse_r
int move_reverse_rotate_r(t_ps *st, int print_flag)
{
	if (move_reverse_rotate_a(st, 0) + move_reverse_rotate_b(st, 0) != 17)
		return (-17);
	else
	{
		if (print_flag == 1)
			ft_printf("rrr\n");
		return (17);
	}
}
