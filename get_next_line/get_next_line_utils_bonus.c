/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:07:37 by jeelee            #+#    #+#             */
/*   Updated: 2022/08/20 16:20:01 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	get_now(t_buff *buffers, int fd)
{
	size_t	now;

	if (fd == 0)
		return (0);
	now = 1;
	while (now < 10000 && buffers[now].fd)
	{
		if (buffers[now].fd == fd)
			return (now);
		now++;
	}
	buffers[now].fd = fd;
	return (now);
}

size_t	ft_strlen(char *str)
{
	size_t	size;

	if (!str)
		return (0);
	size = 0;
	while (str[size])
		size++;
	return (size);
}

size_t	set_line_into(char *new_line, char *line, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		new_line[i] = line[i];
		i++;
	}
	return (i);
}
