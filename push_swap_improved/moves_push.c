/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:48 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/25 10:21:10 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
// Functions to create
//  - push_a
void	move_push(t_st **src, t_st **dst)
{
	t_st	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

// - push_a
void	push_a(t_st **src, t_st **dst)
{
	if (!(*src))
		return ;
	move_push(src, dst);
	ft_printf("pa\n");
}

//  - push_b
void	push_b(t_st **src, t_st **dst)
{
	if (!(*src))
		return ;
	move_push(src, dst);
	ft_printf("pb\n");
}
