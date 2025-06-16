/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:34:20 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/17 15:33:36 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	rotate(t_list **list)
{
	t_list	*aux;
	t_list	*aux2;

	if (!(*list) || !(*list)->next)
		return ;
	else
	{
		aux = *list;
		aux2 = (*list)->next;
		while ((*list)->next)
			*list = (*list)->next;
		(*list)->next = aux;
		aux->next = NULL;
		*list = aux2;
	}
}

void	double_rotate(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}
