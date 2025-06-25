/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:11:03 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/25 10:21:34 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Functions to create
// - move_rotate
void	move_rotate(t_st **src)
{
	t_st	*first;
	t_st	*last;

	first = *src;
	last = stack_last(src);
	*src = first->next;
	first->next = NULL;
	last->next = first;
}

// - rotate_a
void	rotate_a(t_st **st)
{
	if (!(*st) || !(*st)->next)
		return ;
	move_rotate(st);
	ft_printf("ra\n");
}

// - rotate_b
void	rotate_b(t_st **st)
{
	if (!(*st) || !(*st)->next)
		return ;
	move_rotate(st);
	ft_printf("rb\n");
}

// - rotate_r
void	rotate_r(t_st **st_a, t_st **st_b)
{
	if (!(*st_a) || !(*st_b) || !(*st_a)->next || !(*st_b)->next)
		return ;
	move_rotate(st_a);
	move_rotate(st_b);
	ft_printf("rr\n");
}
