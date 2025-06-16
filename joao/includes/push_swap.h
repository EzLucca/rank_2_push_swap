/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:07:49 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/23 10:27:49 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

typedef struct s_helper
{
	int		len;
	int		shortest_largest;
	int		shortest_2nd_largest;
	bool	reverse_flag;
	bool	from_2nd;
}	t_helper;

// main
void			exit_failure(char *error);
bool			check_sorted(t_list *a);
static bool		fill_stack_a(t_list **a, char **array);

// get arguments

static char		**oneline_arguments(char **argv);
static char		**multiple_arguments(int argc, char **argv);
char			**get_arguments(int argc, char **argv);

// check arguments
static int		array_lenght(char **array);
static bool		check_digits(char **array);
static bool		check_boundaries(char **array);
static bool		check_duplicates(long *array, int lenght);
bool			check_arguments(char **array);

// quick sorting
static void		swap_position(long *a, long *b);
static int		partition(long *str, int lower, int higher);
int				quick_sort(long *str, int lower, int higher);

// list utils
void			free_list(t_list *a, t_list *b);
int				size_list(t_list *list);
static t_list	*last_node(t_list *node);
bool			create_node(t_list **list, int number);

// push operation
void			push(t_list **list_from, t_list **list_to, char *msg);

// swap operation
void			swap(t_list *list, char *msg);
void			double_swap(t_list *a, t_list *b);

// rotate operation
void			rotate(t_list **list, char *msg);
void			double_rotate(t_list **a, t_list **b);

// reverese rotate
void			reverse_rotate(t_list **list, char *msg);
void			double_reverse_rotate(t_list **a, t_list **b);

// sorting utils
static int		find_largest(t_list *list);
void			sorting_three_numbers(t_list **list);
long			*transfer_into_array(t_list *list, int len);

// first phase sorting
void			first_phase_sort(t_list **a, t_list **b);
static void		shortest_path_first_phase(t_list **a,
					t_list **b, int mid, int size);
static void		first_phase_push_to_b(t_list **a, t_list **b, int mid_value_a);

// first phase utils
int				find_mid_value(t_list *list, int size_list);
void			rotate_some_a(t_list **list, int nbr, char *msg);
void			reverse_rotate_some_a(t_list **list, int nbr, char *msg);

// second phase
void			second_phase_sorting(t_list **a, t_list **b);
int				select_largest(t_list **b, int nbr,
					t_helper *aux, bool flag_to_2nd);
void			shortest_path_second_phase(t_list **b, int largest, int len);

// second phase utils
void			push_second_largest(t_list **a,
					t_list **b, int largest, t_helper *aux);
void			push_largest(t_list **a, t_list **b,
					int largest, t_helper *aux);
void			reverse_rotate_some_b(t_list **list, int nbr);
void			rotate_some_b(t_list **b, int nbr);

#endif
