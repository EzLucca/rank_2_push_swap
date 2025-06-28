/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:58:41 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 12:22:33 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	error_found(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_exit(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	exit(0);
}

int	max_return(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
