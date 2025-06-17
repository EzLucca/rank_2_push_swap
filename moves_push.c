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
void	move_push(t_stack **st_c, t_stack **st_d)
{
	t_stack	*first;

	first = (*st_c);
	(*st_c) = (*st_c)->next;
	if ((*st_d) == NULL)
		first->next = NULL; 
	else
		first->next = (*st_d);
	(*st_d) = first;
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
