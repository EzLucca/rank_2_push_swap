/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:50:55 by nmeintje          #+#    #+#             */
/*   Updated: 2024/06/28 12:19:00 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *a;
	second_last->next = NULL;
	*a = last;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*b || !(*b)->next)
		return ;
	last = *b;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *b;
	second_last->next = NULL;
	*b = last;
	write(1, "rrb\n", 4);
}

void	ft_rrr_a(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	last = *a;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *a;
	second_last->next = NULL;
	*a = last;
	ft_rrr_b(b);
}

void	ft_rrr_b(t_stack **b)
{
	t_stack	*last;
	t_stack	*second_last;

	last = *b;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *b;
	second_last->next = NULL;
	*b = last;
	write(1, "rrr\n", 4);
}
