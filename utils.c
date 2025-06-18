/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:58:41 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/18 21:55:01 by edlucca          ###   ########.fr       */
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

void	error_found(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_exit(t_stack **st_a, t_stack **st_b)
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
