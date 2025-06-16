/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:15:22 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/17 07:52:53 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_list *list, char *msg)
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
	ft_putstr_fd(msg, 1);
}

void	double_swap(t_list *a, t_list *b)
{
	swap(a, "");
	swap(b, "");
	ft_putstr_fd("ss\n", 1);
}
