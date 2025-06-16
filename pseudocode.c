/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudocode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:15:21 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/16 17:11:32 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_arrays(char **av)
{
	int	i;

	i = 0;

	if (av)
	{
		while(av[i])
		{
			free(av[i]);
			av[i] = NULL;
			i++;
		}
		free(av);
	}
}

void free_stack(t_ps **st)
{
	t_ps	*tmp;

	if(!st || !*st)
		return ;
	while (*st)
	{
		tmp = (*st)->next;
		free(*st);
		*st = tmp;
	}
}

char **input_validation(char **av, bool split)
{
	if (split == true)
	{
		av = ft_split(av[1], ' ');
		split = true;
		if (!av)
		{
			ft_putstr_fd("Error\n", 2);
			free_arrays(av);
			exit(1);
		}
	}
	else
		av = av + 1;
	return(av);
}

void check_repetition(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if(!ft_strncmp(av[j], av[i], sizeof(int)))
			{
				ft_putstr_fd("Error\n", 2);
				exit(19);
			}
			j++;
		}
		i++;
	}
}

int	ft_isdigit_mod(int c)
{
	if ((c >= '0' && c <= '9') || c == '+' || c == '-')
		return (1);
	else
		return (0);
}

void	check_int(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if (!ft_isdigit_mod(av[i][j]))
			{
				ft_putstr_fd("Error\n", 2);
				exit(20);
			}
			j++;
		}
		i++;
	}
}

void parse_av(char **av)
{
	check_repetition(av);
	check_int(av);
}

void	long_check(char *str)
{
	int		x;
	char	*ou_flow;

	if (ft_strcmp(str, "-0") == 0)
		return ;
}

void	push_swap(char **av, t_ps **st)
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

int main(int ac, char **av)
{
	t_ps *stack;
	bool	split;

	split = false;
	if (ac == 2)
		split = true;
	av = input_validation(av, split);
	parse_av(av);
	push_swap(av, &stack);
	if (split == true)
		free_arrays(av);
	free_stack(&stack);
	return (0);
}


/* main
 *	|
 *	|->	input validation |
 *	|					 |-> Correcting type and formats of argv
 *	|->  parsing	|
 *	|				|-> Check for repetition
 *	|				|-> Check for integers 
 *	|->  stacking sorting
 *	|->  freeing everithing
 *	|->  end of program
 *
 */
