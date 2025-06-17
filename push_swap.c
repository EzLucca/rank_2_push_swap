/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:23:25 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/17 15:21:02 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	long_check(char *str)
{
	int		x;
	char	*ou_flow;

	if (ft_strcmp(str, "-0") == 0)
		return ;
	x = ft_atoi(str);
	ou_flow = ft_itoa(x);
	if (ft_strcmp(str, ou_flow) != 0)
	{
		free(ou_flow);
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	free(ou_flow);
}

void	push_swap(char **av, t_stack **st)
{
	int i;
	int len;

	i = 0;
	while (av[i])
	{
		long_check(av[i]);
		i++;
	}
	while (av[i])
	{
		if(!add_node(st, ft_atoi(av[i++])))
			error(st, 1);
	}
	len = gimme_length(*st);
	if (len == 1 || len == 0)
		error(st, 2);
	gimme_index(st, len);
	instructions(st, len);
}
