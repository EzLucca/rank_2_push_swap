/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:36:31 by hutzig            #+#    #+#             */
/*   Updated: 2025/06/17 14:49:43 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free_array(char **args)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}

void	ft_free_stack(t_stack **a)
{
	t_stack	*tmp;

	if (!a)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

void	exit_success(t_stack **a, t_stack **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
	exit(EXIT_SUCCESS);
}

void	exit_failure(t_stack **a, t_stack **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
	ft_error();
}
