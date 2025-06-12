/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:19:23 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/14 10:34:36 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)-> next;
		(*stack)-> nbr = 0;
		free(*stack);
		*stack = tmp;
	}
}
void	free_strs_stack(char **strs, t_stack **stack)
{
	if (strs)
		free_str(strs);
	if (stack)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_str(char **str)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

/*
	fd = 2, is for standard error
*/
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/*
	the order should be in ascending.
	Attention:
		when while loop the stack, the condtion should be "tmp -> next != NULL",
		 not "tmp != NULL"
	Return value:
		1:	sorted;
		0:	not sorted;
*/
int	is_sorted(t_stack *stack)
{
	t_stack		*tmp;

	if (!stack || !(stack -> next))
		return (1);
	tmp = stack;
	while (tmp -> next)
	{
		if (tmp -> nbr > (tmp -> next)-> nbr)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}
