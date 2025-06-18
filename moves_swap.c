/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:39 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/17 15:21:01 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_swap(t_stack **st)
{
	t_stack	*tmp;

	tmp = *st;
	*st = (*st)->next;
	tmp->next = (*st)->next;
	(*st)->next = tmp;
}

// move_sa
void	swap_a(t_stack **st)
{
	move_swap(st);
	ft_printf("sa\n");
}

// move_sb
void	swap_b(t_stack **st)
{
	move_swap(st);
	ft_printf("sb\n");
}
// move_ss
void	swap_s(t_stack **st_a, t_stack **st_b)
{
	move_swap(st_a);
	move_swap(st_b);
	ft_printf("ss\n");
}
