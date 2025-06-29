/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:07:46 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/29 15:12:47 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_append(int fd, char *buffer, char *tmp_buf, ssize_t bytes)
{
	char	*new_buffer;

	while (!ft_strchr_gnl(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, tmp_buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		tmp_buf[bytes] = '\0';
		new_buffer = ft_strjoin_gnl(buffer, tmp_buf);
		if (!new_buffer)
		{
			free (buffer);
			return (NULL);
		}
		free (buffer);
		buffer = new_buffer;
	}
	return (buffer);
}

static char	*read_from_file(int fd, char *buffer)
{
	char	*tmp_buf;
	char	*result;
	ssize_t	bytes;

	tmp_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buf)
		return (NULL);
	bytes = 1;
	result = read_and_append(fd, buffer, tmp_buf, bytes);
	free (tmp_buf);
	return (result);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	size_t	i;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_substr_gnl(buffer, 0, i + 1);
	else
		line = ft_substr_gnl(buffer, 0, i);
	return (line);
}

static char	*update_buffer(char *buffer)
{
	char	*rest_of_line;
	char	*newline_ptr;
	size_t	rest_len;

	newline_ptr = ft_strchr_gnl(buffer, '\n');
	if (!newline_ptr)
	{
		free(buffer);
		return (NULL);
	}
	rest_len = ft_strlen(newline_ptr + 1);
	rest_of_line = ft_substr_gnl(newline_ptr + 1, 0, rest_len);
	if (!rest_of_line)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (rest_of_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = read_from_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}
