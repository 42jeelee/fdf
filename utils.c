/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:45:37 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/04 19:57:49 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_map(t_map *map)
{
	if (map)
	{
		if (map->map)
			free(map->map);
		if (map->mapinit)
			free(map->mapinit);
		free(map);
		map = 0;
	}
	return (0);
}

int	error_massage(char *message, int ret)
{
	write(2, message, ft_strlen(message));
	return (ret);
}

void	cam_init(t_cam *cam)
{
	cam->x = 0;
	cam->y = 0;
	cam->color = 0;
	cam->h = 10;
	cam->big = 1;
	cam->x_angle = 35.264;
	cam->y_angle = 0;
	cam->z_angle = 45;
}

void	map_init(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width * map->height)
		(map->map)[i] = (map->mapinit)[i];
}

void	map_all_init(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->high = 0;
	map->low = 2147483647;
	map->mid = 0;
	map->mapinit = 0;
	map->map = 0;
}
