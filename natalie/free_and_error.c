/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:25:51 by nmeintje          #+#    #+#             */
/*   Updated: 2024/07/15 09:18:28 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	ft_free_str(char **stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (stack[i])
	{
		free(stack[i]);
		stack[i] = NULL;
		i++;
	}
	free(stack);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}
