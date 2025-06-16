/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:00:20 by nmeintje          #+#    #+#             */
/*   Updated: 2024/07/22 17:10:39 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_split_string(char **argv)
{
	t_stack	*stack_a;
	char	**temp;
	int		i;
	int		j;

	stack_a = NULL;
	i = 0;
	temp = ft_split(argv[1], ' ');
	while (temp[i])
	{
		j = ft_atoi(temp[i]);
		ft_lstadd_back(&stack_a, ft_lstnew(j));
		i++;
	}
	ft_free_str(temp);
	return (stack_a);
}

int	ft_atoi(const char *str)
{
	long int	n;
	int			sign;

	n = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (*str == '\0')
		ft_error();
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		n = n * 10 + *str - 48;
		str++;
	}
	if ((sign * n) > INT_MAX || (sign * n) < INT_MIN)
		ft_error();
	return (sign * n);
}

static char	*new_ptr(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (0);
	return (str);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*str;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	ptr = new_ptr(len);
	if (!ptr)
		return (0);
	s += start;
	str = ptr;
	*(ptr + len) = '\0';
	while (len-- && *s)
	{
		*ptr++ = *s++;
	}
	return (str);
}
