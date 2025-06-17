/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:34:43 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/17 15:21:05 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_last(t_stack **st)
{
	t_stack	*tmp;

	tmp = *st;
	while(tmp->next)
		tmp = tmp->next;
	return(tmp);
}

int	ft_stack_size(t_stack **st)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *st;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
