/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:22:51 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/21 15:17:52 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_list **list, char *msg)
{
	t_list	*aux;
	t_list	*aux2;

	if (!(*list) || !(*list)->next)
		return ;
	else
	{
		aux = *list;
		aux2 = *list;
		while (aux->next)
		{
			if (aux->next->next)
				aux2 = aux2->next;
			aux = aux->next;
		}
		aux2->next = NULL;
		aux->next = *list;
		*list = aux;
	}
	ft_putstr_fd(msg, 1);
}

void	double_reverse_rotate(t_list **a, t_list **b)
{
	reverse_rotate(a, "");
	reverse_rotate(b, "");
	ft_putstr_fd("rrr\n", 1);
}
