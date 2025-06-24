/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:06:38 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/24 18:22:38 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static void	read_av(int ac, char **av, t_stack *st_a, t_stack *st_b)
{
	char **array;

	if (ac == 2)
	{
		if (av[1][0] == '\0' || av[1][0] == ' ')
			free_exit(&st_a, &st_b);
		array = ft_split(av[1], ' ');
		if (!array)
			free_exit(&st_a, &st_b);
		create_stack(ac, av, &st_a);
		if (!st_a)
		{
			ft_free_array(array);
			free_exit(&st_a, &st_b);
		}
		ft_free_array(array);
	}
}

static void	operations(t_stack *st_a, t_stack *st_b, char *str)
{
	if (!ft_strncmp(str, "sa\n",3))
		swap_a(&st_a);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap_b(&st_b);
	else if (!ft_strncmp(str, "pa\n", 3))
		push_a(&st_a, &st_b);
	else if (!ft_strncmp(str, "pb\n", 3))
		push_b(&st_a, &st_b);
	else if (!ft_strncmp(str, "ss\n", 3))
		swap_s(&st_a, &st_b);
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate_a(&st_a);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate_b(&st_b);
	else if (!ft_strncmp(str, "rr\n", 3))
		rotate_r(&st_a, &st_b);
	else if (!ft_strncmp(str, "rra\n", 4))
		reverse_rotate_a(&st_a);
	else if (!ft_strncmp(str, "rrb\n", 4))
		reverse_rotate_b(&st_b);
	else if (!ft_strncmp(str, "rrr\n", 4))
		reverse_rotate_r(&st_a, &st_b);
	else
	{
		free(str);
		free_exit(&st_a, &st_b);
	}
}

int	main(int ac, char **av)
{
	t_stack *st_a;
	t_stack *st_b;
	char	*next_line;

	create_stack(ac, av, &st_a);
	if(ac == 1)
		return (0);
	read_av(ac, av, st_a, st_b);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		operations(st_a, st_b, next_line);
		free(next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (ascending_check(&st_a) && st_b == 0) 
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_exit(&st_a, &st_b);
}
