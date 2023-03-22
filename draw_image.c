/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:52:09 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/23 01:30:52 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
  char *dst;

  dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

void	draw_image(t_map *map, t_img *img)
{
	t_dot	d1;
	int		i;

	i = -1;
	while (++i < map->height * map->width)
	{
		d1 = (map->map)[i];
		my_mlx_pixel_put(img, d1.x, d1.y, 0xFF0000);
	}
}
