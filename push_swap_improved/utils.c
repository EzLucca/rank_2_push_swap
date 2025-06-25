/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:58:41 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/25 10:22:47 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	free_stack(t_st **st)
{
	t_st	*tmp;

	if (!st || !*st)
		return ;
	while (*st)
	{
		tmp = (*st)->next;
		free(*st);
		*st = tmp;
	}
}

void	error_found(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_exit(t_st **st_a, t_st **st_b)
{
	free_stack(st_a);
	free_stack(st_b);
	exit(0);
}

int	max_return(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

// void print_stack(t_st *stack, char *name)
// {
// 	ft_printf("Stack %s: ", name);
// 	while (stack)
// 	{
// 		ft_printf("%d ", stack->nbr);
// 		stack = stack->next;
// 	}
// 	ft_printf("\n");
// }
