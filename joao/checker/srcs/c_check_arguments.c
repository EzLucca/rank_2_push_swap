/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_check_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:36:15 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/23 10:30:18 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static bool	check_digits(char **array)
{
	int		i;
	int		j;
	bool	neg;

	i = 0;
	neg = false;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (ft_isdigit(array[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	array_lenght(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static bool	check_boundaries(char **array)
{
	int		i;
	int		j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if ((array[i][j] == '-' && !ft_isdigit(array[i][j + 1])) ||
				(array[i][j] == '+' && !ft_isdigit(array[i][j + 1])))
				return (0);
			if (j >= 1 && !ft_isdigit(array[i][j]) &&
			ft_isdigit(array[i][j - 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static bool	check_duplicates(long *array, int lenght)
{
	int	i;

	i = 0;
	while (i < lenght - 1)
	{
		if (array[i] == array[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	check_arguments(char **array)
{
	long	*str;
	int		i;

	i = 0;
	if (check_digits(array) || !check_boundaries(array))
		return (false);
	str = malloc(sizeof(long) * array_lenght(array));
	if (!str)
		return (false);
	while (array[i])
	{
		str[i] = ft_atol(array[i]);
		if (str[i] > 2147483647 || str[i++] < -2147483648)
		{
			free(str);
			return (false);
		}
	}
	if (!quick_sort(str, 0, i - 1) && !check_duplicates(str, i))
	{
		free(str);
		return (false);
	}
	free(str);
	return (true);
}
