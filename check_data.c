/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:16:00 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/18 13:53:43 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_args(int ac, char **av)
{
	char **args;
	int		i;

	args = NULL;
	i = 0;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			error_found();
	}
	else
		args = av + 1;
	while (args[i])
	{
		if (syntax_check(args[i]) || !int_check(args[i]))
		{
			if (ac == 2)
				free_arrays(args);
			error_found();
		}
		i++;
	}
	return (args);
}

void	stack_append(t_stack **st_a, int nbr)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		free_stack(st_a);
		error_found();
	}
	new->nbr = nbr;
	new->next = NULL;
	if (*st_a == NULL)
		*st_a = new;
	else
	{
		last = stack_last(st_a);
		last->next = new;
	}
}

void	create_stack (int ac, char **av, t_stack **st_a)
{
	char	**args;
	int		nbr;
	int		i;

	i = 0;
	args = check_args(ac, av);
	while (args[i])
	{
		nbr = ft_atoi(args[i]);
		stack_append(st_a, nbr);
		i++;
	}
	if (ac == 2)
		free_arrays(args);
}
