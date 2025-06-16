/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:15:22 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/17 08:22:05 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	swap(t_list *list)
{
	int	aux;

	if (!list || !list->next)
		return ;
	else
	{
		aux = list->data;
		list->data = list->next->data;
		list->next->data = aux;
	}
}

void	double_swap(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
}
