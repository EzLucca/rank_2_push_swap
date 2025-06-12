/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:16:12 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/06 11:55:02 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_validation(int ac, char **av, t_ps *st)
{
	int i;
	int number_count;

	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) == 0)
			return (-1);
	}
	number_count = number_validation(ac, av);
	if (number_count == -1)
		return (-1);
	if (initialize_stacks(ac, av, st, number_count) == -1)
	{
		free_stacks(st);
		return (-2);
	}
	if (double_validation(st)== -1)
	{
		free_stacks(st);
		return (-3);
	}
	return (0);
}

// number_validation
int	number_validation(int ac, char **av)
{
	int i;
	int j;
	int	count;
	char **array;

	count = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		array = ft_split(av[i++], ' ');
		if(!array)
			return(-1);
		while (array[j])
		{
			if (ft_isnum(array[j]) && (ft_strlen(array[j]) < 3 || ft_atoi(array[j]) != 0))
				count++;
			else
				return(/*free 2d array*/);
			j++;
		}
		// free 2d array
	}
	return (count);
}

// initialize_stacks
int	initialize_stacks(int ac, char **av, t_ps *st, int number_count)
{
	int	i;
	int	j;
	int	k;
	char **array;

	st->a = malloc(sizeof(int) * (number_count));
	st->b = malloc(sizeof(int) * (number_count));
	if(!st->a || !st->b)
		return(-1);
	k = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		array = ft_split(av[i++], ' ');
		if(!array)
			return(-1);
		while (array[j])
			st->a[k++] = ft_atoi(arr[j++]);
		//free array
	}
	st->ac = number_count + 1;
	st->height_a = st->ac -1;
	st->height_b = 0;
	return (0);
}

// check for doubles
int	double_validation(t_ps *st)
{
	int	i;
	int	j;

	i = 0;
	while (i < st->height_a)
	{
		j = i + 1;
		while (j < st->height_a)
		{
			if (st->a[i] == st->a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return(1);
}

int	ft_isnum(char *str)
{
	int	i;

	if (!str || ft_strlen(str) == 0)
		return (0);
	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (ft_strlen(str) == 1)
			return (0);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
