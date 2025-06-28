/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:10:39 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 12:21:10 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_swap(t_stack **src)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = (*src)->next;
	(*src)->next = tmp;
}

void	swap_a(t_stack **stack)
{
	if (!(*stack) || (*stack)->next == NULL)
		return ;
	move_swap(stack);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack)
{
	if (!(*stack) || (*stack)->next == NULL)
		return ;
	move_swap(stack);
	ft_printf("sb\n");
}

void	swap_s(t_stack **a, t_stack **b)
{
	if (!(*a) || !(*b) || !(*a)->next || !(*b)->next)
		return ;
	move_swap(a);
	move_swap(b);
	ft_printf("ss\n");
}
