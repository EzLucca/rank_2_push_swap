/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:10:52 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/04/11 09:50:07 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*rest;

	first = (*stack)->next;
	rest = first->next;
	first->next = (*stack);
	(*stack)->next = rest;
	(*stack) = first;
}

void	sa(t_stack **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_stack **stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}
