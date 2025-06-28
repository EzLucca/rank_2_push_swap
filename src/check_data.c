/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:16:00 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 15:23:51 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Validates and prepares arguments for stack creation.
 *
 * Checks the given arguments for validity (e.g., digits, duplicates),
 * and splits the input if needed (e.g., when argc == 2).
 *
 * @param argc Argument count from main.
 * @param argv Argument vector from main.
 * @return A NULL-terminated array of strings representing individual numbers.
 *         This array must be freed by the caller (use ft_free_array).
 */
char	**check_args(int argc, char **argv)
{
	char	**args;
	int		i;

	args = NULL;
	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			error_found();
	}
	else
		args = argv + 1;
	while (args[i])
	{
		if (syntax_check(args[i]) || !int_check(args[i]))
		{
			if (argc == 2)
				ft_free_array(args);
			error_found();
		}
		i++;
	}
	return (args);
}

/**
 * @brief Appends a new number to the end of stack A.
 *
 * Creates a new stack node with the given number and appends it
 * to the end of the linked list pointed to by `a`.
 *
 * @param a Pointer to the head of stack A.
 * @param nbr The integer value to append to the stack.
 */
void	stack_append(t_stack **a, int nbr)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		free_stack(a);
		error_found();
	}
	new->nbr = nbr;
	new->next = NULL;
	if (*a == NULL)
		*a = new;
	else
	{
		last = stack_last(a);
		last->next = new;
	}
}

/**
 * @brief Creates the initial stack A from program arguments.
 *
 * Parses the input arguments, converts them to integers, and appends
 * them to stack A. If the input was passed as a single string (argc == 2),
 * it frees the temporary split array after use.
 *
 * @param argc The argument count from main.
 * @param argv The argument vector from main.
 * @param a Pointer to the stack A where numbers will be stored.
 */
void	create_stack(int argc, char **argv, t_stack **a)
{
	char	**args;
	int		nbr;
	int		i;

	i = 0;
	args = check_args(argc, argv);
	while (args[i])
	{
		nbr = ft_atoi(args[i]);
		stack_append(a, nbr);
		i++;
	}
	if (argc == 2)
		ft_free_array(args);
}
