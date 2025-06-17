/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:09:09 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/17 15:21:07 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **st)
{
	t_stack	*tmp;

	if(!st || !*st)
		return ;
	while (*st)
	{
		tmp = (*st)->next;
		free(*st);
		*st = tmp;
	}
}

void	free_arrays(char **av)
{
	int	i;

	i = 0;

	if (av)
	{
		while(av[i])
		{
			free(av[i]);
			av[i] = NULL;
			i++;
		}
		free(av);
	}
}

void	error(t_stack **st, int num)
{
	if (num == 1)
		ft_putstr_fd("Error\n", 2);
	free_stack(st);
	exit(1);
}
