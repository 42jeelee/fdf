/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:51:37 by jeelee            #+#    #+#             */
/*   Updated: 2022/08/20 16:55:56 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	end_line(t_buff *buffer)
{
	size_t	size;

	size = 0;
	while (buffer->idx < (size_t)buffer->rd_size)
	{
		if ((buffer->buff)[buffer->idx] == '\n')
		{
			size++;
			(buffer->idx)++;
			break ;
		}
		size++;
		(buffer->idx)++;
	}
	return (size);
}

char	*cat_line(char *line, t_buff *buffer)
{
	char	*new_line;
	size_t	size;
	size_t	l_size;
	size_t	i;

	size = end_line(buffer);
	l_size = ft_strlen(line);
	new_line = (char *)malloc(sizeof(char) * (l_size + size + 1));
	if (!new_line)
	{
		if (line)
			free(line);
		return (NULL);
	}
	i = set_line_into(new_line, line, l_size);
	buffer->idx -= size;
	while (i < l_size + size)
	{
		new_line[i] = (buffer->buff)[(buffer->idx)++];
		i++;
	}
	new_line[i] = 0;
	if (line)
		free(line);
	return (new_line);
}

char	*make_line(t_buff *buffer)
{
	char	*line;

	line = NULL;
	while (1)
	{
		if (!buffer->idx || buffer->idx == (size_t)buffer->rd_size)
		{
			buffer->rd_size = read(buffer->fd, buffer->buff, BUFFER_SIZE);
			buffer->idx = 0;
			if (buffer->rd_size < 1)
				break ;
		}
		line = cat_line(line, buffer);
		if (!line)
			return (NULL);
		if ((buffer->buff)[buffer->idx - 1] == '\n' || \
		buffer->rd_size < BUFFER_SIZE)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_buff	buffer;

	buffer.fd = fd;
	line = NULL;
	if (BUFFER_SIZE > 0)
	{
		line = make_line(&buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}
