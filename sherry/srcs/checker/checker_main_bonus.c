/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:41:10 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/12 13:22:34 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/checker_bonus.h"

/*
	operate when the instruction is in rra, rrb or rrr condition.
*/
void	check_sub(t_stack **a, t_stack **b, char *instrcs)
{
	if (instrcs[2] == 'a')
		rev_rotate_bns(a);
	else if (instrcs[2] == 'b')
		rev_rotate_bns(b);
	else if (instrcs[2] == 'r')
		rev_rotate_rrr_bns(a, b);
}

/*
	Check the instructions and execute them.
*/
char	*check(t_stack **a, t_stack **b, char *instrcs)
{
	if (instrcs[0] == 's' && instrcs[1] == 'a' && instrcs[2] == '\n')
		swap_bns(a);
	else if (instrcs[0] == 's' && instrcs[1] == 'b' && instrcs[2] == '\n')
		swap_bns(b);
	else if (instrcs[0] == 's' && instrcs[1] == 's' && instrcs[2] == '\n')
	{
		swap_bns(a);
		swap_bns(b);
	}
	else if (instrcs[0] == 'p' && instrcs[1] == 'a' && instrcs[2] == '\n')
		push_bns(b, a);
	else if (instrcs[0] == 'p' && instrcs[1] == 'b' && instrcs[2] == '\n')
		push_bns(a, b);
	else if (instrcs[0] == 'r' && instrcs[1] == 'a' && instrcs[2] == '\n')
		rotate_bns(a);
	else if (instrcs[0] == 'r' && instrcs[1] == 'b' && instrcs[2] == '\n')
		rotate_bns(b);
	else if (instrcs[0] == 'r' && instrcs[1] == 'r' && instrcs[2] == '\n')
		rotate_rr_bns(a, b);
	else if (instrcs[0] == 'r' && instrcs[1] == 'r' && instrcs[3] == '\n')
		check_sub(a, b, instrcs);
	else
		ft_error(4);
	return (get_next_line(0));
}

/*
	The function is doing:
	- read the instructions from standard input(meaning from the terminal) and execute
	  them;
	- After execute all the instructions check if the stack_b is empty. If it is empty
	  print"KO";
	- Check if stack_a is sorted. If it isn't sorted, then print "KO";
	- Other conditions, print "OK"
*/
void	checker(t_stack **a, t_stack **b, char *instrcs)
{
	char	*tmp;

	while (instrcs && *instrcs != '\n')
	{
		tmp = instrcs;
		instrcs = check(a, b, instrcs);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!is_sorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(instrcs);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	char		*instrcs;

	a = process_args(ac, av);
	b = NULL;
	if (!a || is_duplicated(a))
	{
		free_stack(&a);
		ft_error(3);
	}
	instrcs = get_next_line(0);
	if (!instrcs && !is_sorted(a))
		write(1, "KO\n", 3);
	else if (!instrcs && is_sorted(a))
		write(1, "OK\n", 3);
	else
		checker(&a, &b, instrcs);
	free_stack(&a);
	free_stack(&b);
	exit(0);
}
