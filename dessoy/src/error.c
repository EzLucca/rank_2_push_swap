/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:33:47 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/04/09 19:13:55 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_handling(t_stack **stack, int num)
{
	if (num == 1)
		ft_putstr_fd(ERR, 2);
	free_ll(stack);
	exit(1);
}
