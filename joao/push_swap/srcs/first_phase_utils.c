/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_phase_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:41:13 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/23 10:31:01 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_some_a(t_list **list, int nbr, char *msg)
{
	rotate(list, msg);
	while (--nbr > 0)
		rotate(list, msg);
}

void	reverse_rotate_some_a(t_list **list, int nbr, char *msg)
{
	reverse_rotate(list, msg);
	while (--nbr >= 0)
		reverse_rotate(list, msg);
}

int	find_mid_value(t_list *list, int size_list)
{
	long	*array;
	int		i;

	array = transfer_into_array(list, size_list);
	quick_sort(array, 0, size_list - 1);
	i = (int)array[size_list / 2];
	free(array);
	array = NULL;
	return (i);
}
