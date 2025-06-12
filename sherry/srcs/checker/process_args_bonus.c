/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:20:29 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/14 10:46:25 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

int	is_duplicated(t_stack *stack)
{
	t_stack		*tmp_outer;
	t_stack		*tmp_inner;

	if (!stack || !(stack -> next))
		return (0);
	tmp_outer = stack;
	while (tmp_outer)
	{
		tmp_inner = tmp_outer -> next;
		while (tmp_inner)
		{
			if ((tmp_outer -> nbr) == (tmp_inner -> nbr))
				return (1);
			tmp_inner = tmp_inner -> next;
		}
		tmp_outer = tmp_outer -> next;
	}
	return (0);
}

/*
	sub_process is to split (seperator is space) *str to **str, then add each valid
	integer into stack a.
*/
void	sub_process(char *str, t_stack **a)
{
	char		**split_str;
	int			i;
	int			j;

	i = 0;
	split_str = ft_split(str, 32);
	if (!split_str || !(*split_str))
		free_strs_stack(split_str, a, 6);
	while (split_str[i])
	{
		j = ft_atoi_v2(split_str[i], split_str, a);
		stack_add_back(a, stack_newnode(j));
		i++;
	}
	free_str(split_str);
}

/*
	upgrade version of ft_atoi, it will call ft_error() when the error is found.
	Here it will show error:
	- when there is non-integer characters;
	- when it is overflow.
*/
int	ft_atoi_v2(char *str, char **strs, t_stack **stack)
{
	long long int	num;
	int				sign;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (!*(str + 1))
			free_strs_stack(strs, stack, 1);
		else if (*str++ == '-')
			sign = -1;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			free_strs_stack(strs, stack, 1);
		num = num * 10 + *str - '0';
		str++;
	}
	if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
		free_strs_stack(strs, stack, 2);
	return ((num * sign));
}

/*
	Function process_args will do three things:
	1. return error if the the number of argument is less than 2;
	2. call sub_process if the number of argument is 2;
	3. ELse, changing each arument into integer and added them at the end of the stack.

	Return value:
	It will return a empty stack if the argument is less than 2. Otherwise, it will return
	a pointer point to the beginning of stack a .
*/
t_stack	*process_args(int argc, char **argv)
{
	t_stack		*a;
	int			i;

	a = NULL;
	i = 1;
	if (argc <= 1)
		exit(1);
	else if (argc > ARG_MAX_NUM)
		ft_error(5);
	while (i < argc)
	{
		sub_process(argv[i], &a);
		i++;
	}
	return (a);
}
