/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:39:05 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/28 10:51:54 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checkinput(char *argv[], int start);

static int	checkinput_case(char *argv[], int start, int i);

static int	checknum(char *str);

//function takes arguments, checks the input and
// then passes them for futher processing

int	push_swap(int argc, char *argv[])
{
	char	**argv_new;
	int		start;

	start = 0;
	if (argc < 2)
		exit(0);
	if (argc == 2)
		argv_new = ft_split(argv[1], ' ');
	else
	{
		argv_new = argv;
		start = 1;
	}
	if (checkinput(argv_new, start) == 0)
	{
		write(2, "Error\n", 6);
		if (argc == 2)
			free_arr(argv_new);
		exit(0);
	}
	swap_algo(argc, argv_new);
	return (0);
}

// the function is checking if the input is correct

static int	checkinput(char *argv[], int start)
{
	int		i;

	i = start;
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		if (checknum(argv[i]) == 0)
			return (0);
		i++;
	}
	i = start;
	while (argv[i])
	{
		if (checkinput_case(argv, start, i) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	checkinput_case(char *argv[], int start, int i)
{
	int		j;

	j = start + 1;
	while (argv[j])
	{
		if (ft_atoi(argv[i]) == ft_atoi(argv[j]) && i != j)
			return (0);
		j++;
	}
	return (1);
}

// the function is checking if passed argument is integer

static int	checknum(char *str)
{
	int		j;

	j = 0;
	if (str[0] == '-')
		j++;
	if (str[j] == '\0')
		return (0);
	while (str[j] != '\0')
	{
		if (ft_isdigit(str[j]) == 0)
			return (0);
		j++;
	}
	if (j > 11)
		return (0);
	if (ft_atoi_long(str) > INT_MAX || ft_atoi_long(str) < INT_MIN)
		return (0);
	return (1);
}
