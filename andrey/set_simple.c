/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:27:30 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/28 09:54:47 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// the function converts numbers provided by user to simplified indexes

void	set_simple(t_int **lst)
{
	t_int	*temp1;
	t_int	*temp2;
	int		count_smaller;

	temp1 = *lst;
	while (temp1)
	{
		temp2 = *lst;
		count_smaller = 0;
		while (temp2)
		{
			if (temp1->content > temp2->content)
				count_smaller++;
			temp2 = temp2->next;
		}
		temp1->simple = count_smaller;
		temp1 = temp1->next;
	}
}

// the function finds the smallest simplified index from the list and returns it

int	get_min(t_int *lst)
{
	int		num_min;

	num_min = lst->simple;
	while (lst->next)
	{
		if (lst->simple > lst->next->simple)
			num_min = lst->next->simple;
		lst = lst->next;
	}
	return (num_min);
}
