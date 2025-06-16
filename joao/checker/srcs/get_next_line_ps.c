/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:07:10 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/17 15:32:42 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static int	line_check(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] != '\n')
		return (0);
	return (1);
}

static int	process_line(char **container, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	while ((*container)[i] != '\n' && (*container)[i] != '\0')
		i++;
	if ((*container)[i] == '\n')
	{
		*line = ft_substr(*container, 0, i);
		temp = ft_strdup(&((*container)[i + 1]));
		free(*container);
		*container = temp;
		if ((*container)[0] == '\0')
			ft_strdel(container);
		return (1);
	}
	else
	{
		*line = ft_strdup(*container);
		ft_strdel(container);
		return (0);
	}
}

static int	return_value(char **container, char **line, int res, int fd)
{
	if (res < 0)
		return (-1);
	if (!res && !container[fd])
	{
		*line = ft_strdup("\0");
		return (0);
	}
	return (process_line(&container[fd], line));
}

int	get_next_line_ps(int fd, char **line)
{
	static char	*container[OPEN_MAX];
	char		*buffer;
	char		*aux;
	int			res;

	res = 1;
	buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (fd < 0 || !line || BUFFER_SIZE < 1 || !buffer)
		return (-1);
	while (res > 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (!container[fd])
			container[fd] = ft_strdup(buffer);
		else
		{
			aux = ft_strjoin(container[fd], buffer);
			free(container[fd]);
			container[fd] = aux;
		}
		if (line_check(buffer))
			break ;
	}
	ft_strdel(&buffer);
	return (return_value(container, line, res, fd));
}
