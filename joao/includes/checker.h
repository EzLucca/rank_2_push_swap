/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:07:49 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/23 10:30:45 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

// main
void			exit_failure(char *error);
static bool		fill_stack_a(t_list **a, char **array);
static bool		proceed_operations(char *operation, t_list **a, t_list **b);
static bool		get_operations(t_list **a, t_list **b);

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
bool			check_sorted(t_list *a);

// push operation
void			push(t_list **list_from, t_list **list_to);

// swap operation
void			swap(t_list *list);
void			double_swap(t_list *a, t_list *b);

// rotate operation
void			rotate(t_list **list);
void			double_rotate(t_list **a, t_list **b);

// reverese rotate
void			reverse_rotate(t_list **list);
void			double_reverse_rotate(t_list **a, t_list **b);

// get next line Push_Swap
static int		line_check(const char *str);
static int		process_line(char **container, char **line);
static int		return_value(char **container, char **line, int res, int fd);
int				get_next_line_ps(int fd, char **line);

#endif
