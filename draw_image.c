/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:52:09 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/23 16:31:23 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < img->width && y < img->height)
	{
		dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_image(t_map *map, t_img *img)
{
	t_dot	*d1;
	t_dot	*d2;
	// t_dot	*d3;
	int		i;

	d1 = &((map->map)[0]);
	i = 0;
	while (++i < map->height * map->width)
	{
		d2 = &((map->map)[i]);
		bresenham(d1, d2, img);
		d1 = d2;
	}
}
