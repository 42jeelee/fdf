/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:52:09 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/26 20:34:18 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if ((0 <= x && x < img->width) && (0 <= y && y < img->height))
	{
		dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_image(t_map *map, t_img *img)
{
	t_dot	*d1;
	t_dot	*d2;
	t_dot	*d3;
	int		i;

	d1 = &((map->map)[0]);
	i = 0;
	while (++i < map->height * map->width)
	{
		d2 = &((map->map)[i]);
		if (i % map->width)
			bresenham(d1, d2, img);
		if (i + map->width - 1 < map->height * map->width)
		{
			d3 = &((map->map)[i + map->width - 1]);
			bresenham(d1, d3, img);
		}
		d1 = d2;
	}
}
