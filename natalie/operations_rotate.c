/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:38:49 by nmeintje          #+#    #+#             */
/*   Updated: 2024/07/16 17:19:25 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	temp = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	last->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	temp = *b;
	last = ft_lstlast(*b);
	*b = (*b)->next;
	last->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rr_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	temp = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	last->next = temp;
	temp->next = NULL;
	ft_rr_b(b);
}

void	ft_rr_b(t_stack **b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	temp = *b;
	last = ft_lstlast(*b);
	*b = (*b)->next;
	last->next = temp;
	temp->next = NULL;
	write(1, "rr\n", 3);
}
