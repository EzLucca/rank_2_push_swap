/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:59:43 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/17 13:38:29 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void parse_av(char **av)
{
	check_repetition(av);
	check_int(av);
}

char	**input_validation(char **av, bool split)
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

void	check_repetition(char **av)
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
