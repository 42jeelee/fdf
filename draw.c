/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:50:12 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/21 22:18:12 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_next_dot(t_dot *d2, t_vars *vars)
{
	d2->x = WINDOW_MARGIN + (vars->gap * d2->x);
	d2->y = WINDOW_MARGIN + (vars->gap * d2->y);
}

void	draw_map(t_mapinfo *mapinfo, t_vars *vars, t_img *img)
{
	t_dot	d1;
	t_dot	d2;
	t_dot	d3;
	int		i;

	print_window_size(vars);
	d1 = (mapinfo->map)[0];
	d1.x += WINDOW_MARGIN;
	d1.y += WINDOW_MARGIN;
	i = 0;
	while (++i < (mapinfo->width * mapinfo->height))
	{
		d2 = (mapinfo->map)[i];
		set_next_dot(&d2, vars);
		if (i % mapinfo->width)
			bresenhams(d1, d2, img);
		if (i + mapinfo->width - 1 < (mapinfo->width * mapinfo->height))
		{
			d3 = (mapinfo->map)[i + mapinfo->width - 1];
			set_next_dot(&d3, vars);
			bresenhams(d1, d3, img);
		}
		d1 = d2;
	}
}
