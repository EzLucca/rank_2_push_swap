/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:02:40 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/28 09:57:22 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	b_to_a_first_number(t_int **lst1, t_int **lst2, int i);

static int	b_to_a_second_number(t_int **lst1, t_int **lst2, int i);

static int	b_to_a_second_number_cases(t_int **lst1, t_int **lst2, int i);

// the function uses the algorithm to sort the stack containing 5 elements

void	algo_5(t_int **lst1, t_int **lst2)
{
	int		i;

	push_b(lst1, lst2);
	push_b(lst1, lst2);
	if ((*lst2)->simple < (*lst2)->next->simple)
		swap_b(lst2);
	algo_3(lst1);
	i = 0;
	i = b_to_a_first_number(lst1, lst2, i);
	i = b_to_a_second_number(lst1, lst2, i);
	if (*lst2)
		push_a(lst1, lst2);
	while (i > 0)
	{
		r_rotate_a(lst1);
		i--;
	}
	while (i < 0)
	{
		rotate_a(lst1);
		i++;
	}
}

static int	b_to_a_first_number(t_int **lst1, t_int **lst2, int i)
{
	if ((*lst2)->simple > (*lst1)->next->next->simple)
	{
		push_a(lst1, lst2);
		i--;
	}
	else
	{
		while ((*lst2)->simple > (*lst1)->simple)
		{
			rotate_a(lst1);
			i++;
		}
		push_a(lst1, lst2);
	}
	return (i);
}

static int	b_to_a_second_number(t_int **lst1, t_int **lst2, int i)
{
	if ((*lst2)->simple < get_min(*lst1))
	{
		while (i > 0)
		{
			r_rotate_a(lst1);
			i--;
		}
		while (i < 0)
		{
			rotate_a(lst1);
			i++;
		}
		push_a(lst1, lst2);
	}
	if ((*lst2) && (*lst2)->simple < (*lst1)->simple && \
			(*lst2)->simple > (*lst1)->next->next->next->simple)
	{
		push_a(lst1, lst2);
		if (i == -1)
			i--;
	}
	i = b_to_a_second_number_cases(lst1, lst2, i);
	return (i);
}

static int	b_to_a_second_number_cases(t_int **lst1, t_int **lst2, int i)
{
	if ((*lst2) && (*lst1)->next->next->simple == get_min(*lst1))
	{
		while ((*lst2)->simple < (*lst1)->next->next->next->simple || \
			(*lst2)->simple > (*lst1)->simple)
		{
			r_rotate_a(lst1);
			i--;
		}
		push_a(lst1, lst2);
	}
	if ((*lst2) && (*lst2)->simple < (*lst1)->next->next->next->simple && \
			(*lst2)->simple > (*lst1)->next->next->simple)
	{
		r_rotate_a(lst1);
		i = i - 2;
		push_a(lst1, lst2);
	}
	while ((*lst2) && ((*lst2)->simple < (*lst1)->next->next->next->simple || \
			(*lst2)->simple > (*lst1)->simple))
	{
		rotate_a(lst1);
		i++;
	}
	return (i);
}
