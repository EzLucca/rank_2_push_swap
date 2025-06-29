/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:15:14 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/29 18:40:14 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

/**
 * @brief Frees the given string and exits freeing the stacks.
 * 
 * @param a Pointer to stack 'a'.
 * @param b Pointer to stack 'b'.
 * @param str String to be freed.
 */
static void	free_all(t_stack **a, t_stack **b, char *str)
{
	free(str);
	free_exit(a, b);
}

/**
 * @brief Reads command line arguments and creates stack 'a'.
 *
 * If a single argument contains multiple numbers separated by spaces,
 * it splits them before creating the stack.
 * 
 * @param ac Argument count.
 * @param av Argument vector (array of strings).
 * @param a Pointer to stack 'a'.
 * @param b Pointer to stack 'b'.
 */
static void	read_av(int ac, char **av, t_stack **a, t_stack **b)
{
	char	**array;

	if (ac == 2)
	{
		if (av[1][0] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			free_exit(a, b);
		}
		array = ft_split(av[1], ' ');
		if (!array)
			free_exit(a, b);
		create_stack(ac, array, a);
		if (!a || duplicates_check(*a))
		{
			ft_free_array(array);
			free_exit(a, b);
		}
		ft_free_array(array);
	}
	else
		create_stack(ac, av, a);
	if (!(*a) || duplicates_check(*a))
	{
		ft_putstr_fd("Error\n", 2);
		free_exit(a, b);
	}
}

/**
 * @brief Executes the stack operation based on the given instruction string.
 * 
 * @param a Pointer to stack 'a'.
 * @param b Pointer to stack 'b'.
 * @param str Instruction string to execute.
 */
static void	operations(t_stack **a, t_stack **b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap_a(a);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap_b(b);
	else if (!ft_strncmp(str, "pa\n", 3))
		push_a(b, a);
	else if (!ft_strncmp(str, "pb\n", 3))
		push_b(a, b);
	else if (!ft_strncmp(str, "ss\n", 3))
		swap_s(a, b);
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate_a(a);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate_b(b);
	else if (!ft_strncmp(str, "rr\n", 3))
		rotate_r(a, b);
	else if (!ft_strncmp(str, "rra\n", 4))
		reverse_rotate_a(a);
	else if (!ft_strncmp(str, "rrb\n", 4))
		reverse_rotate_b(b);
	else if (!ft_strncmp(str, "rrr\n", 4))
		reverse_rotate_r(a, b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		free_all(a, b, str);
	}
}

/**
 * @brief Main program function that controls the flow.
 *
 * Reads arguments, executes operations, and verifies final stack order.
 * 
 * @param ac Argument count.
 * @param av Argument vector.
 * @return int Exit code (0 on success).
 */
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*instructions;

	if (ac == 1)
		return (0);
	a = NULL;
	b = NULL;
	read_av(ac, av, &a, &b);
	instructions = get_next_line(STDIN_FILENO);
	while (instructions)
	{
		operations(&a, &b, instructions);
		free(instructions);
		instructions = get_next_line(STDIN_FILENO);
	}
	if (ascending_check(&a) && (!b || b->next == NULL))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_exit(&a, &b);
}
