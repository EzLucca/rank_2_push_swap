/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:19:44 by nmeintje          #+#    #+#             */
/*   Updated: 2024/08/12 11:54:14 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

void	calculate_steps_to_head(t_stack **head, t_stack *node, t_steps *steps)
{
	int		forward_dist;
	int		reverse_dist;
	int		total_size;
	t_stack	*current;

	forward_dist = 0;
	reverse_dist = 0;
	total_size = ft_lstsize(*head);
	steps->rotate = 0;
	steps->reverse = 0;
	current = *head;
	while (current != NULL)
	{
		if (current == node)
			break ;
		current = current->next;
		forward_dist++;
	}
	reverse_dist = total_size - forward_dist;
	if (forward_dist <= reverse_dist)
		steps->rotate = forward_dist;
	else
		steps->reverse = reverse_dist;
}

int	ft_move_cost(t_stack **a, t_stack **b, t_stack *cur_a, t_stack *tar_b)
{
	int	min_steps;
	int	rev_steps;

	min_steps = max(dist_w_rot(cur_a, a), dist_w_rot(tar_b, b));
	rev_steps = max(dist_w_rev(cur_a, a), dist_w_rev(tar_b, b));
	if (dist_w_rot(cur_a, a) + dist_w_rev(tar_b, b) < min_steps)
		min_steps = dist_w_rot(cur_a, a) + dist_w_rev(tar_b, b);
	if (dist_w_rev(cur_a, a) + dist_w_rot(tar_b, b) < min_steps)
		min_steps = dist_w_rev(cur_a, a) + dist_w_rot(tar_b, b);
	if (rev_steps < min_steps)
		min_steps = rev_steps;
	return (min_steps);
}

int	dist_w_rot(t_stack *current, t_stack **head)
{
	int		dist;
	t_stack	*temp;

	temp = *head;
	dist = 0;
	if (current == NULL || head == NULL)
		return (-1);
	while (temp && current)
	{
		if (temp == current)
			return (dist);
		temp = temp->next;
		dist++;
	}
	return (-1);
}

int	dist_w_rev(t_stack *current, t_stack **head)
{
	int	dist;
	int	dist_rot;

	dist = 0;
	if (current == NULL || head == NULL)
		return (dist);
	dist_rot = dist_w_rot(current, head);
	if (dist_rot == -1)
		return (-1);
	dist = ft_lstsize(*head) - dist_rot;
	return (dist);
}
