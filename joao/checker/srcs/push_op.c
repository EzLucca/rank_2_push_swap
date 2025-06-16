/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:25:00 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/17 08:18:58 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	push(t_list **list_from, t_list **list_to)
{
	t_list	*aux;

	if (!(*list_from))
		return ;
	else
	{
		aux = *list_from;
		*list_from = (*list_from)->next;
		aux->next = *list_to;
		*list_to = aux;
	}
}
