/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:00:58 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/29 15:34:31 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*fail_read_map(t_map *map, int fd)
{
	free_map(map);
	close(fd);
	return (NULL);
}

int	get_map_width(char *line)
{
	int		width;
	int		i;
	t_dot	tmp;

	width = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\n')
			break ;
		if (!('0' <= line[i] && line[i] <= '9') && \
			(!(line[i] == '-' && ('0' <= line[i + 1] && line[i + 1] <= '9'))))
			return (-1);
		if (map_atoi(line, &tmp, &i) == -1)
			return (-1);
		width++;
	}
	return (width);
}

int	put_map_byline(char *line, t_map *map)
{
	int	i;
	int	idx;

	idx = 0;
	i = map->width * (map->height - 1);
	while (i < map->width * map->height)
	{
		while (line[idx] == ' ')
			idx++;
		if (!('0' <= line[idx] && line[idx] <= '9') && \
			(!(line[idx] == '-' && \
				('0' <= line[idx + 1] && line[idx + 1] <= '9'))))
			return (-1);
		(map->mapinit)[i].x = i - (map->width * (map->height - 1));
		(map->mapinit)[i].y = map->height - 1;
		if (map_atoi(line, &(map->mapinit)[i], &idx) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	read_map(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	map->height = 1;
	map->width = get_map_width(line);
	if (map_widthjoin(map) == -1)
		return (-1);
	if (put_map_byline(line, map) == -1)
		return (-1);
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		map->height++;
		if (map_widthjoin(map) == -1)
			return (-1);
		if (put_map_byline(line, map) == -1)
			return (-1);
	}
	return (0);
}

t_map	*get_map(char *filename)
{
	t_map	*map;
	int		fd;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = 0;
	map->width = 0;
	map->mapinit = 0;
	fd = open(filename, O_RDONLY);
	if (read_map(fd, map) == -1)
		return (fail_read_map(map, fd));
	map->map = (t_dot *)malloc(sizeof(t_dot) * (map->width * map->height));
	if (!map->mapinit)
		return (fail_read_map(map, fd));
	map_init(map);
	close(fd);
	return (map);
}
