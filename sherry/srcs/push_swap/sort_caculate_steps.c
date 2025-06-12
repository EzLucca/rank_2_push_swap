/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_caculate_steps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:42:02 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/09 12:51:48 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
	To caculate if pushing a num from stack_a to stack_b, the chepeast step is how many.
*/
int	find_cheapest_steps_to_b(t_stack *a, t_stack *b)
{
	t_stack		*tmp;
	int			steps;

	steps = if_rarb(a, b, a -> nbr, 1);
	tmp = a;
	while (tmp)
	{
		if (steps > if_rarb(a, b, tmp -> nbr, 1))
			steps = if_rarb(a, b, tmp -> nbr, 1);
		if (steps > if_rarrb(a, b, tmp -> nbr, 1))
			steps = if_rarrb(a, b, tmp -> nbr, 1);
		if (steps > if_rrarb(a, b, tmp -> nbr, 1))
			steps = if_rrarb(a, b, tmp -> nbr, 1);
		if (steps > if_rrarrb(a, b, tmp -> nbr, 1))
			steps = if_rrarrb(a, b, tmp -> nbr, 1);
		tmp = tmp -> next;
	}
	return (steps);
}

/*
	To caculate if pushing a num from stack_b to stack_a, the chepeast step is how many.
*/
int	find_cheapest_steps_to_a(t_stack *a, t_stack *b)
{
	t_stack		*tmp;
	int			steps;

	steps = if_rarb(a, b, b -> nbr, 2);
	tmp = b;
	while (tmp)
	{
		if (steps > if_rarb(a, b, tmp -> nbr, 2))
			steps = if_rarb(a, b, tmp -> nbr, 2);
		if (steps > if_rarrb(a, b, tmp -> nbr, 2))
			steps = if_rarrb(a, b, tmp -> nbr, 2);
		if (steps > if_rrarb(a, b, tmp -> nbr, 2))
			steps = if_rrarb(a, b, tmp -> nbr, 2);
		if (steps > if_rrarrb(a, b, tmp -> nbr, 2))
			steps = if_rrarrb(a, b, tmp -> nbr, 2);
		tmp = tmp -> next;
	}
	return (steps);
}
