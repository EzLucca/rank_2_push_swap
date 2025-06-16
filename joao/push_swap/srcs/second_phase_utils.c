/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_phase_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:24:52 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/23 10:30:49 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_some_b(t_list **b, int nbr)
{
	while (nbr-- > 0)
		rotate(b, "rb\n");
}

void	reverse_rotate_some_b(t_list **list, int nbr)
{
	while (nbr-- > 0)
		reverse_rotate(list, "rrb\n");
}

void	push_largest(t_list **a, t_list **b, int largest, t_helper *aux)
{
	shortest_path_second_phase(b, largest, size_list(*b));
	push(b, a, "pa\n");
	if (aux->from_2nd == true)
		swap(*a, "sa\n");
}

void	push_second_largest(t_list **a, t_list **b, int largest, t_helper *aux)
{
	if (aux->reverse_flag == true)
		reverse_rotate_some_b(b, aux->shortest_2nd_largest);
	else
		rotate_some_b(b, aux->shortest_2nd_largest);
	push(b, a, "pa\n");
	aux->from_2nd = true;
	push_largest(a, b, largest, aux);
}
