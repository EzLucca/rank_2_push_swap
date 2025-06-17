/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:10:17 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/04/10 11:32:47 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	add_node(t_stack **stack, int value)
{
	t_stack	*curr;
	t_stack	*end;

	curr = (t_stack *)malloc(sizeof(t_stack));
	if (!curr)
		return (0);
	curr->index = -1;
	curr->next = NULL;
	curr->nb = value;
	curr->len = 0;
	if (!(*stack))
		*stack = curr;
	else
	{
		end = list_last(*stack);
		end->next = curr;
	}
	return (1);
}

t_stack	*list_last(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	gimme_length(t_stack *lst)
{
	int	len;

	len = 1;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

void	free_ll(t_stack **stack)
{
	t_stack		*current;
	t_stack		*temp;

	current = *stack;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}

int	stack_order(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (tmp->next != NULL)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
