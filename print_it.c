/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:01:03 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/27 03:21:41 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_map(t_map *map)
{
	int	i;

	if (!map)
		printf("MAP NULL point\n");
	else
	{
		printf("---map---\nwidth: %d\nheight: %d\n", \
			map->width, map->height);
		if (map->map)
		{
			i = -1;
			while (++i < map->height * map->width)
			{
				printf("%d ", (map->map)[i].z);
				if (!((i + 1) % map->width))
					printf("\n");
			}
		}
		else
			printf("MAP->map is null\n");
	}
}

void	print_color(t_map *map)
{
	int	i;

	if (!map)
		printf("MAP NULL point\n");
	else
	{
		printf("---map---\nwidth: %d\nheight: %d\n", \
			map->width, map->height);
		if (map->map)
		{
			i = -1;
			while (++i < map->height * map->width)
			{
				printf("(%d) ", (map->map)[i].color);
				if (!((i + 1) % map->width))
					printf("\n");
			}
		}
		else
			printf("MAP->map is null\n");
	}
}

void	print_xy(t_map *map)
{
	int	i;

	if (!map)
		printf("MAP NULL point\n");
	else
	{
		printf("---map---\nwidth: %d\nheight: %d\n", \
			map->width, map->height);
		if (map->map)
		{
			i = -1;
			while (++i < map->height * map->width)
			{
				printf("(%d, %d) ", (map->map)[i].x, (map->map)[i].y);
				if (!((i + 1) % map->width))
					printf("\n");
			}
		}
		else
			printf("MAP->map is null\n");
	}
}

void	print_dot(t_dot *dot)
{
	printf("\n++PRINT DOT++\n");
	printf("D(%d, %d)\n", dot->x, dot->y);
}

void	print_info(t_map *map, t_mlx *mlx, t_img *img)
{
	printf("======INFO=======\n");
	printf("MAP HEIGHT: %d\nMAP WIDTH: %d\n", map->height, map->width);
	printf("GAP: %d\nMLX HEIGHT: %d\nMLX WIDTH: %d\n", \
		mlx->gap, mlx->height, mlx->width);
	printf("IMG BIT..: %d\nIMG SIZELINE: %d\nIMG ENDIAN: %d\n", \
		img->bits_per_pixel, img->size_line, img->endian);
	printf("=================\n");
}
