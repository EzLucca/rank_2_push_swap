/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:39 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/25 10:21:43 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	move_swap(t_st **src)
{
	t_st	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = (*src)->next;
	(*src)->next = tmp;
}

// move_sa
void	swap_a(t_st **st)
{
	if (!(*st) || (*st)->next == NULL)
		return ;
	move_swap(st);
	ft_printf("sa\n");
}

// move_sb
void	swap_b(t_st **st)
{
	if (!(*st) || (*st)->next == NULL)
		return ;
	move_swap(st);
	ft_printf("sb\n");
}

// move_ss
void	swap_s(t_st **st_a, t_st **st_b)
{
	if (!(*st_a) || !(*st_b) || !(*st_a)->next || !(*st_b)->next)
		return ;
	move_swap(st_a);
	move_swap(st_b);
	ft_printf("ss\n");
}
