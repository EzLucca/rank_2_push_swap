/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stacklist1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:29:56 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/09 12:54:10 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_add_back(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (*stack)
		(stack_last(*stack))-> next = new;
	else
		*stack = new;
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack-> next)
		stack = stack-> next;
	return (stack);
}

t_stack	*stack_newnode(int content)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode -> nbr = content;
	newnode -> next = NULL;
	return (newnode);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	tmp = stack;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp-> next;
	}
	return (size);
}
