/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_basic_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:19:23 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/14 10:40:51 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

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

void	free_strs_stack(char **strs, t_stack **stack, int error_type)
{
	if (strs)
		free_str(strs);
	if (stack)
		free_stack(stack);
	ft_error(error_type);
}

/*
	The fucntion is for print error message and exit the program.

	Type:
		1: non-integer found, print message "Must be all numbers" and change to newline;
		2: input is overflowed, print message "Input is overflowed" and change to newline;
		3: dupicated nummbers, print message "Duplicated numbers" and change to newline;
		4: the input instruction is wrong, print message "Instruction is not correct" and change to newline;
*/
void	ft_error(int type)
{
	if (type == 1)
		write(2, "Error! Must be all numbers\n", 27);
	else if (type == 2)
		write(2, "Error! Input is overflowed\n", 27);
	else if (type == 3)
		write(2, "Error! Duplicated numbers\n", 26);
	else if (type == 4)
		write(2, "Error! Instruction is not correct\n", 34);
	else if (type == 5)
		write(2, "Error! Too many arguments!\n", 27);
	else
		write(2, "Error!\n", 7);
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
