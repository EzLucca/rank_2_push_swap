/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:38:27 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/28 10:52:47 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algo_options(int argc, t_int **lst1, t_int **lst2);

static int	stacks_fill(int argc, char *argv[], t_int **lst1, t_int **lst2);

// the function allocates memory for 2 stacks and passes them
// to helper functions to fill the stack a, to perform
// the sorting operations on the stacks and to free them

void	swap_algo(int argc, char *argv[])
{
	t_int	**stack_a;
	t_int	**stack_b;
	int		argc_new;

	stack_a = (t_int **)malloc((argc - 1) * sizeof(t_int));
	if (stack_a == NULL)
		exit(0);
	stack_b = (t_int **)malloc((argc - 1) * sizeof(t_int));
	if (stack_b == NULL)
	{
		free(stack_a);
		exit(0);
	}
	*stack_a = NULL;
	*stack_b = NULL;
	argc_new = stacks_fill(argc, argv, stack_a, stack_b);
	if (argc == 2)
		free_arr(argv);
	algo_options(argc_new, stack_a, stack_b);
	free_stacks(stack_a, stack_b);
}

// the function is filling the stack a (linked list)
// with arguments provided by user

static int	stacks_fill(int argc, char *argv[], t_int **lst1, t_int **lst2)
{
	int		i;
	int		new_num;
	t_int	*new;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		new_num = ft_atoi(argv[i]);
		new = ft_lstnew_int(new_num, 0);
		if (new == NULL)
		{
			free_stacks(lst1, lst2);
			exit(0);
		}
		ft_lstadd_back_int(lst1, new);
		i++;
	}
	if (argc == 2)
		return (i + 1);
	return (argc);
}

// the function is passing the stack(s) to chosen
// algorithm after adding simplified indexes
// to every node and checking if the stack a is already sorted

static void	algo_options(int argc, t_int **lst1, t_int **lst2)
{
	set_simple(lst1);
	if (a_is_sorted(*lst1) == 0)
	{
		free_stacks(lst1, lst2);
		exit(0);
	}
	if (argc == 3)
		algo_2(lst1);
	if (argc == 4)
		algo_3(lst1);
	if (argc == 5)
		algo_4(lst1, lst2);
	if (argc == 6)
		algo_5(lst1, lst2);
	if (argc >= 7)
		algo_large(lst1, lst2);
}
