/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:13:22 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/28 10:54:00 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// the function rotates stack a (moves element
// on top of stack to the bottom of stack)

void	rotate_a(t_int **lst1)
{
	t_int	*temp1;
	int		first_simp;

	if (!(*lst1) || !((*lst1)->next))
		return ;
	temp1 = *lst1;
	first_simp = temp1->simple;
	while (temp1->next)
	{
		temp1->simple = temp1->next->simple;
		temp1 = temp1->next;
	}
	temp1->simple = first_simp;
	ft_printf("ra\n");
}

// the function rotates stack b (moves element
// on top of stack to the bottom of stack)

void	rotate_b(t_int **lst1)
{
	t_int	*temp1;
	int		first_simp;

	if (!(*lst1) || !((*lst1)->next))
		return ;
	temp1 = *lst1;
	first_simp = temp1->simple;
	while (temp1->next)
	{
		temp1->simple = temp1->next->simple;
		temp1 = temp1->next;
	}
	temp1->simple = first_simp;
	ft_printf("rb\n");
}

// the function reverse rotates stack a (moves last element on top of stack)

void	r_rotate_a(t_int **lst1)
{
	t_int	*temp1;
	int		up_simp;
	int		pull_simp;
	int		last_simp;

	if (!(*lst1) || !((*lst1)->next))
		return ;
	temp1 = *lst1;
	last_simp = temp1->simple;
	pull_simp = temp1->simple;
	while (temp1)
	{
		if (!temp1->next)
		{
			last_simp = temp1->simple;
		}
		up_simp = temp1->simple;
		temp1->simple = pull_simp;
		pull_simp = up_simp;
		temp1 = temp1->next;
	}
	(*lst1)->simple = last_simp;
	ft_printf("rra\n");
}

// the function reverse rotates stack b (moves last element on top of stack)

void	r_rotate_b(t_int **lst1)
{
	t_int	*temp1;
	int		up_simp;
	int		pull_simp;
	int		last_simp;

	if (!(*lst1) || !((*lst1)->next))
		return ;
	temp1 = *lst1;
	last_simp = temp1->simple;
	pull_simp = temp1->simple;
	while (temp1)
	{
		if (!temp1->next)
		{
			last_simp = temp1->simple;
		}
		up_simp = temp1->simple;
		temp1->simple = pull_simp;
		pull_simp = up_simp;
		temp1 = temp1->next;
	}
	(*lst1)->simple = last_simp;
	ft_printf("rrb\n");
}
