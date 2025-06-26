/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:11:03 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/26 18:01:22 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Functions to create
// - move_rotate
void	move_rotate(t_stack **src)
{
	t_stack	*first;
	t_stack	*last;

	first = *src;
	last = stack_last(src);
	*src = first->next;
	first->next = NULL;
	last->next = first;
}

// - rotate_a
void	rotate_a(t_stack **st)
{
	if (!(*st) || !(*st)->next)
		return ;
	move_rotate(st);
	ft_printf("ra\n");
}

// - rotate_b
void	rotate_b(t_stack **st)
{
	if (!(*st) || !(*st)->next)
		return ;
	move_rotate(st);
	ft_printf("rb\n");
}

// - rotate_r
void	rotate_r(t_stack **st_a, t_stack **st_b)
{
	if (!(*st_a) || !(*st_b) || !(*st_a)->next || !(*st_b)->next)
		return ;
	move_rotate(st_a);
	move_rotate(st_b);
	ft_printf("rr\n");
}
