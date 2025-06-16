/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:31:36 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/23 08:36:11 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	exit_failure(char *error)
{
	ft_putstr_fd(error, 2);
	exit(1);
}

static bool	fill_stack_a(t_list **a, char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (!create_node(a, ft_atoi(array[i++])))
		{
			ft_free_char_array(array);
			return (false);
		}
	}
	ft_free_char_array(array);
	return (true);
}

static bool	proceed_operations(char *operation, t_list **a, t_list **b)
{
	if (!ft_strncmp(operation, "pa", 3))
		push(a, b);
	else if (!ft_strncmp(operation, "pb", 3))
		push(b, a);
	else if (!ft_strncmp(operation, "sa", 3))
		swap(*a);
	else if (!ft_strncmp(operation, "sb", 3))
		swap(*b);
	else if (!ft_strncmp(operation, "ss", 3))
		double_swap(*a, *b);
	else if (!ft_strncmp(operation, "ra", 3))
		rotate(a);
	else if (!ft_strncmp(operation, "rb", 3))
		rotate(b);
	else if (!ft_strncmp(operation, "rr", 3))
		double_rotate(a, b);
	else if (!ft_strncmp(operation, "rra", 4))
		reverse_rotate(a);
	else if (!ft_strncmp(operation, "rrb", 4))
		reverse_rotate(b);
	else if (!ft_strncmp(operation, "rrr", 4))
		double_reverse_rotate(a, b);
	else
		return (false);
	return (true);
}

static bool	get_operations(t_list **a, t_list **b)
{
	char	*operation;
	int		res;

	operation = NULL;
	res = 1;
	while (res > 0)
	{
		res = get_next_line_ps(STDIN_FILENO, &operation);
		if ((!proceed_operations(operation, a, b) || res == -1) && res != 0)
		{
			free(operation);
			return (false);
		}
		free(operation);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	char	**array;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || ft_strncmp(argv[1], "", 1) != 0)
		return (1);
	array = get_arguments(argc, argv);
	if (!check_arguments(array) || !fill_stack_a(&a, array)
		|| !get_operations(&a, &b))
	{
		free_list(a, b);
		ft_free_char_array(array);
		exit_failure("Error\n");
	}
	if (!b && a && check_sorted(a) == true)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_list(a, b);
	ft_free_char_array(array);
	return (0);
}
