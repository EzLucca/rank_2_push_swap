/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:44:41 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/21 15:17:50 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap_position(long *a, long *b)
{
	long	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(long *str, int lower, int higher)
{
	int	pivot;
	int	i;
	int	j;

	pivot = str[higher];
	i = lower - 1;
	j = lower;
	while (j <= higher - 1)
	{
		if (str[j] <= pivot)
			swap_position(&str[++i], &str[j]);
		j++;
	}
	swap_position(&str[i + 1], &str[higher]);
	return (i + 1);
}

int	quick_sort(long *str, int lower, int higher)
{
	int	pivot;

	if (lower < higher)
	{
		pivot = partition(str, lower, higher);
		quick_sort(str, lower, pivot - 1);
		quick_sort(str, pivot + 1, higher);
	}
	return (0);
}
