/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:48 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/17 15:20:39 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Functions to create
//  - push_a
void	move_push(t_stack **src, t_stack **dst)
{
	t_stack	*first;

	first = (*src);
	(*src) = (*src)->next;
	if ((*dst) == NULL)
		first->next = NULL; 
	else
		first->next = (*dst);
	(*dst) = first;
}

// - push_a
void	push_a(t_stack **st_b, t_stack **st_a)
{
	if (*st_b != NULL)
	{
		move_push(st_b, st_a);
		ft_printf("pa\n");
	}
}

//  - push_b
void	push_b(t_stack **st_a, t_stack **st_b)
{
	if (*st_a != NULL)
	{
		move_push(st_a, st_b);
		ft_printf("pb\n");
	}
}
