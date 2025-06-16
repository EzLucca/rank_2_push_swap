/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:38:04 by nmeintje          #+#    #+#             */
/*   Updated: 2024/07/24 14:27:24 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_refine(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		j;

	i = 1;
	stack_a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		stack_a = ft_split_string(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi(argv[i]);
			ft_lstadd_back(&stack_a, ft_lstnew(j));
			i++;
		}
	}
	return (stack_a);
}

static int	ft_check_repeats(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->num == temp->num)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}

int	ft_check_sorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->num;
	while (stack_a)
	{
		if (i > stack_a->num)
			return (0);
		i = stack_a->num;
		stack_a = stack_a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = ft_refine(argc, argv);
	if (!stack_a || ft_check_repeats(stack_a))
	{
		ft_free(&stack_a);
		ft_error();
	}
	if (!ft_check_sorted(stack_a))
	{
		ft_sort(&stack_a);
	}
	ft_free(&stack_a);
	return (0);
}
