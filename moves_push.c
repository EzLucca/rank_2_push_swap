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
	t_stack	*tmp;

	tmp = (*src);
	(*src) = (*src)->next;
	// if ((*dst) == NULL)
	// 	tmp->next = NULL; 
	// else
	tmp->next = (*dst);
	(*dst) = tmp;
}

// - push_a
void	push_a(t_stack **src, t_stack **dst)
{
	if (!(*src))
		return ;
	move_push(src, dst);
	ft_printf("pa\n");
}

//  - push_b
void	push_b(t_stack **src, t_stack **dst)
{
	if (!(*src))
		return ;
	move_push(src, dst);
	ft_printf("pb\n");
}
