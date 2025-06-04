/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:56:59 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/04 11:41:02 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list stack_a;
	t_list stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return(0);
	else if (ac == 2)
	{
		// if a string is receive split in the arg
		split_av = ft_split(av[1], ' ');
		// initialize one stack with the args form split
		string_stack();
		// free split_av
	}
	else
		// initialize a
		initialize_stack();
	// initialize b
	initialize_stack();
	// algorithm sort call
	//
	// free stack_a and stack_b
	return (0);
}
