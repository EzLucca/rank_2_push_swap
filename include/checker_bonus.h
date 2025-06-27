/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:15:53 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/25 10:16:12 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

void	move_push(t_stack **src, t_stack **dst);
void	push_a(t_stack **src, t_stack **dst);
void	push_b(t_stack **src, t_stack **dst);

void	move_swap(t_stack **src);
void	swap_a(t_stack **st);
void	swap_b(t_stack **st);
void	swap_s(t_stack **a, t_stack **b);

void	move_rotate(t_stack **src);
void	rotate_a(t_stack **st);
void	rotate_b(t_stack **st);
void	rotate_r(t_stack **a, t_stack **b);

void	move_reverse_rotate(t_stack **src);
void	reverse_rotate_a(t_stack **st);
void	reverse_rotate_b(t_stack **st);
void	reverse_rotate_r(t_stack **a, t_stack **b);

#endif // !CHECKER_BONUS_H
