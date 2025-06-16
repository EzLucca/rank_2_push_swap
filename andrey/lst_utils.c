/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:40:03 by aklimchu          #+#    #+#             */
/*   Updated: 2024/06/28 10:51:10 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// the function creates a new node

t_int	*ft_lstnew_int(int content, int simple)
{
	t_int	*new;

	new = (t_int *)malloc(sizeof(*new));
	if (new == NULL)
		return ((void *) 0);
	new->content = content;
	new->simple = simple;
	new->next = NULL;
	return (new);
}

// the function adds a node on the top of linked list

void	ft_lstadd_front_int(t_int **lst, t_int *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
	return ;
}

// the function returns a pointer to the last node in the linked list

t_int	*ft_lstlast_int(t_int *lst)
{
	t_int	*temp;

	if (lst == NULL)
		return ((void *) 0);
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

// the function returns the size of the linked list

int	ft_lstsize_int(t_int *lst)
{
	int	i;	

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// the function adds a node to the end of linked list

void	ft_lstadd_back_int(t_int **lst, t_int *new)
{
	t_int	*temp;

	if ((!lst) || (!new))
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = ft_lstlast_int(*lst);
		temp->next = new;
	}
	return ;
}
