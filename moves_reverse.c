/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:55 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/18 21:22:17 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Functions to create
void	reverse_rotate(t_stack **src)
{
	t_stack	*first;
	t_stack	*last;
	
	first = stack_last(src);
	last = (*src);
	while (last->next != NULL)
		last = last->next;
	first->next = (*src);
	last->next = NULL;
	(*src) = first;
}
//  - reverse_a
void	reverse_rotate_a(t_stack **st)
{
	reverse_rotate(st);
	ft_printf("rra\n");
}
//  - reverse_b
void	reverse_rotate_b(t_stack **st)
{
	reverse_rotate(st);
	ft_printf("rrb\n");
}
//  - reverse_r
void	reverse_rotate_r(t_stack **st_a, t_stack **st_b)
{
	reverse_rotate(st_a);
	reverse_rotate(st_b);
	ft_printf("rrr\n");
}
