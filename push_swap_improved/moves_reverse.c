/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:55 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/25 10:21:18 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
// Functions to create
void	reverse_rotate(t_st **src)
{
	t_st	*first;
	t_st	*last;

	first = *src;
	last = NULL;
	while (first->next)
	{
		last = first;
		first = first->next;
	}
	last->next = NULL;
	first->next = *src;
	*src = first;
}

void	reverse_rotate_a(t_st **st)
{
	if (!(*st) || !(*st)->next)
		return ;
	reverse_rotate(st);
	ft_printf("rra\n");
}

//  - reverse_b
void	reverse_rotate_b(t_st **st)
{
	if (!(*st) || !(*st)->next)
		return ;
	reverse_rotate(st);
	ft_printf("rrb\n");
}

//  - reverse_r
void	reverse_rotate_r(t_st **st_a, t_st **st_b)
{
	if (!(*st_a) || !(*st_b) || !(*st_a)->next || !(*st_b)->next)
		return ;
	reverse_rotate(st_a);
	reverse_rotate(st_b);
	ft_printf("rrr\n");
}
