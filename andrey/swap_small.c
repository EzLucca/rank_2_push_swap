/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:18:36 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/28 10:42:51 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algo_3_case(t_int **lst1);

static void	algo_3_case_2(t_int **lst1);

// the function uses the algorithm to sort the stack containing 2 elements

void	algo_2(t_int **lst)
{
	if ((*lst)->simple > (*lst)->next->simple)
		swap_a(lst);
}

// the function uses the algorithm to sort the stack containing 3 elements

void	algo_3(t_int **lst1)
{
	if (a_is_sorted(*lst1) == 0)
		return ;
	if ((*lst1)->simple < (*lst1)->next->simple && \
		(*lst1)->next->simple > (*lst1)->next->next->simple && \
		(*lst1)->simple < (*lst1)->next->next->simple)
		algo_3_case(lst1);
	if ((*lst1)->simple > (*lst1)->next->simple && \
		(*lst1)->next->simple < (*lst1)->next->next->simple && \
		(*lst1)->simple < (*lst1)->next->next->simple)
		swap_a(lst1);
	if ((*lst1)->simple < (*lst1)->next->simple && \
		(*lst1)->next->simple > (*lst1)->next->next->simple && \
		(*lst1)->simple > (*lst1)->next->next->simple)
	{
		rotate_a(lst1);
		rotate_a(lst1);
	}
	algo_3_case_2(lst1);
}

// the function uses the algorithm to sort the stack containing 4 elements

void	algo_4(t_int **lst1, t_int **lst2)
{
	int		i;

	push_b(lst1, lst2);
	algo_3(lst1);
	if ((*lst2)->simple > (*lst1)->next->next->simple)
	{
		push_a(lst1, lst2);
		rotate_a(lst1);
		return ;
	}
	i = 0;
	while ((*lst2)->simple > (*lst1)->simple)
	{
		rotate_a(lst1);
		i++;
	}
	push_a(lst1, lst2);
	while (i > 0)
	{
		r_rotate_a(lst1);
		i--;
	}
}

static void	algo_3_case(t_int **lst1)
{
	rotate_a(lst1);
	swap_a(lst1);
	r_rotate_a(lst1);
}

static void	algo_3_case_2(t_int **lst1)
{
	if ((*lst1)->simple > (*lst1)->next->simple && \
		(*lst1)->next->simple < (*lst1)->next->next->simple && \
		(*lst1)->simple > (*lst1)->next->next->simple)
		rotate_a(lst1);
	if ((*lst1)->simple > (*lst1)->next->simple && \
		(*lst1)->next->simple > (*lst1)->next->next->simple && \
		(*lst1)->simple > (*lst1)->next->next->simple)
	{
		swap_a(lst1);
		r_rotate_a(lst1);
	}
}
