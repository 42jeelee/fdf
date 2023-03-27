/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:45:37 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/27 08:46:50 by jeelee           ###   ########.fr       */
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

void	cam_init(t_mlx *mlx)
{
	(mlx->cam).x = 0;
	(mlx->cam).y = 0;
	(mlx->cam).z = 0;
	(mlx->cam).x_angle = 35.264;
	(mlx->cam).y_angle = 0;
	(mlx->cam).z_angle = 45;
}

void	map_init(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width * map->height)
		(map->map)[i] = (map->mapinit)[i];
}

int	is_in_string(char c, const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (c == str[i] \
			|| (('A' <= str[i] && str[i] <= 'Z') && c == str[i] + 32) \
			|| (('a' <= str[i] && str[i] <= 'z') && c == str[i] - 32))
			return (i);
	}
	return (-1);
}

int	map_widthjoin(t_map *map)
{
	t_dot	*new;
	int		i;

	new = (t_dot *)malloc(sizeof(t_dot) * (map->width * map->height));
	if (!new)
		return (-1);
	i = -1;
	while (++i < map->width * (map->height - 1))
		new[i] = (map->mapinit)[i];
	if (map->mapinit)
		free(map->mapinit);
	map->mapinit = new;
	return (0);
}
