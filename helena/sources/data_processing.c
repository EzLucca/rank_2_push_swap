/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:01:34 by hutzig            #+#    #+#             */
/*   Updated: 2025/06/17 14:49:52 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**args_processing(int argc, char **argv)
{
	char	**args;
	int		i;

	args = NULL;
	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			ft_error();
	}
	else
		args = argv + 1;
	while (args[i])
	{
		if (checking_syntax_error(args[i]) || !checking_is_integer(args[i]))
		{
			if (argc == 2)
				ft_free_array(args);
			ft_error();
		}
		i++;
	}
	return (args);
}

static void	stack_appending(t_stack **a, int nb)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!new)
	{	
		ft_free_stack(a);
		ft_error();
	}
	new->nb = nb;
	new->next = NULL;
	if (*a == NULL)
		*a = new;
	else
	{
		last = ft_stack_last(a);
		last->next = new;
	}
}

void	stack_processing(int argc, char **argv, t_stack **a)
{
	char	**args;
	int		nb;
	int		i;

	i = 0;
	args = args_processing(argc, argv);
	while (args[i])
	{
		nb = ft_atoi(args[i]);
		stack_appending(a, nb);
		i++;
	}
	if (argc == 2)
		ft_free_array(args);
}
