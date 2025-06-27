/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:55 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/26 18:00:52 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack **src)
{
	t_stack	*first;
	t_stack	*last;

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

void	reverse_rotate_a(t_stack **st)
{
	if (!(*st) || !(*st)->next)
		return ;
	reverse_rotate(st);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **st)
{
	if (!(*st) || !(*st)->next)
		return ;
	reverse_rotate(st);
	ft_printf("rrb\n");
}

void	reverse_rotate_r(t_stack **st_a, t_stack **st_b)
{
	if (!(*st_a) || !(*st_b) || !(*st_a)->next || !(*st_b)->next)
		return ;
	reverse_rotate(st_a);
	reverse_rotate(st_b);
	ft_printf("rrr\n");
}
