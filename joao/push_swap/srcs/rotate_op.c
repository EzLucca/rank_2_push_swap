/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:34:20 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/21 15:17:55 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_list **list, char *msg)
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
	ft_putstr_fd(msg, 1);
}

void	double_rotate(t_list **a, t_list **b)
{
	rotate(a, "");
	rotate(b, "");
	ft_putstr_fd("rr\n", 1);
}
