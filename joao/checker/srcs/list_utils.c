/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:39:38 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/17 15:33:00 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	free_list(t_list *a, t_list *b)
{
	t_list	*aux;

	while (a)
	{
		aux = a;
		a = a->next;
		free(aux);
	}
	while (b)
	{
		aux = b;
		b = b->next;
		free(aux);
	}
}

int	size_list(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

static t_list	*last_node(t_list *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

bool	create_node(t_list **list, int number)
{
	t_list	*new;
	t_list	*temp;

	temp = *list;
	new = malloc(sizeof(t_list));
	if (!new)
		return (false);
	else
	{
		new->data = number;
		new->next = NULL;
		if (*list)
		{
			temp = last_node(temp);
			temp->next = new;
		}
		else
			*list = new;
	}
	return (true);
}

bool	check_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (false);
		a = a->next;
	}
	return (true);
}
