/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:38:23 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/14 10:36:42 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*a;

	a = process_args(ac, av);
	if (!a || is_duplicated(a))
	{
		free_stack(&a);
		ft_error();
	}
	if (!is_sorted(a))
		sort_ascending(&a);
	free_stack(&a);
	exit(0);
}
