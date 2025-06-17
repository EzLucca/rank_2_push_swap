/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:11:03 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/17 15:20:55 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Functions to create
// - move_rotate
void	move_rotate(t_stack **st)
{
	t_stack	*first;
	t_stack	*last;

	first = (*st)->next;
	last = ft_stack_last(st);
	last->next = *st;
	(*st)->next = NULL;
	(*st) = first;
}

// - rotate_a
void	rotate_ra(t_stack **st)
{
	move_rotate(st);
	ft_printf("ra\n");
}
// - rotate_b
void	rotate_rb(t_stack **st)
{
	move_rotate(st);
	ft_printf("rb\n");
}
// - rotate_r
void	rotate_rr(t_stack **st_a, t_stack **st_b)
{
	move_rotate(st_a);
	move_rotate(st_b);
	ft_printf("rr\n");
}
