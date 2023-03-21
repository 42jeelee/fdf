/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:02:55 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/21 15:10:37 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *line)
{
	int		width;
	int		idx;
	t_map	tmp;

	width = 0;
	idx = 0;
	while (!(line[idx] == 0 || line[idx] == '\n'))
	{
		if (map_atoi(line, &tmp, &idx) == -1)
			return (-1);
		width++;
	}
	return (width);
}

int	mapjoin(t_mapinfo *mapinfo)
{
	int		i;
	t_map	*tmp;

	if (!mapinfo->map)
	{
		mapinfo->map = (t_map *)malloc(sizeof(t_map) * mapinfo->width);
		if (!mapinfo->map)
			return (-1);
	}
	else
	{
		tmp = (t_map *)malloc(sizeof(t_map) * \
			(mapinfo->width * (mapinfo->height + 1)));
		if (!tmp)
			return (-1);
		i = -1;
		while (++i < mapinfo->width * mapinfo->height)
			tmp[i] = (mapinfo->map)[i];
		free(mapinfo->map);
		mapinfo->map = tmp;
	}
	return (0);
}

int	make_map_byline(char *line, t_mapinfo *mapinfo)
{
	int	x;
	int	idx;

	if (mapjoin(mapinfo) == -1)
		return (-1);
	idx = 0;
	x = (mapinfo->height * mapinfo->width) - 1;
	while (++x < (mapinfo->height * mapinfo->width) \
		+ mapinfo->width - 1)
	{
		if (map_atoi(line, &(mapinfo->map)[x], &idx) != 0)
			return (-1);
	}
	if (map_atoi(line, &(mapinfo->map)[x], &idx) != 1)
		return (-1);
	mapinfo->height++;
	return (0);
}

int	read_map(int fd, t_mapinfo *mapinfo)
{
	char	*line;

	line = get_next_line(fd);
	mapinfo->width = get_width(line);
	mapinfo->height = 0;
	if (make_map_byline(line, mapinfo) == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (make_map_byline(line, mapinfo) == -1)
			return (-1);
	}
	return (0);
}

int	get_map(char *filename, t_mapinfo *mapinfo)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (read_map(fd, mapinfo) == -1)
		return (-1);
	close(fd);
	return (0);
}
