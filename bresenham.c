/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:40:12 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/29 19:04:26 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	_bresenham_x(t_dot curr, t_dot diff, t_dot vec, t_mlx *mlx)
{
	int	i;
	int	p;

	p = 2 * diff.y - diff.x;
	i = -1;
	while (++i < diff.x)
	{
		my_mlx_pixel_put(mlx, curr, \
			get_color(vec.color, diff.color, i, diff.x));
		if (p < 0)
			p += 2 * diff.y;
		else
		{
			p += 2 * (diff.y - diff.x);
			if (vec.y > 0)
				curr.y++;
			else
				curr.y--;
		}
		if (vec.x > 0)
			curr.x++;
		else
			curr.x--;
	}
}

void	_bresenham_y(t_dot curr, t_dot diff, t_dot vec, t_mlx *mlx)
{
	int	i;
	int	p;

	p = 2 * diff.x - diff.y;
	i = -1;
	while (++i < diff.y)
	{
		my_mlx_pixel_put(mlx, curr, \
			get_color(vec.color, diff.color, i, diff.y));
		if (p < 0)
			p += 2 * diff.x;
		else
		{
			p += 2 * (diff.x - diff.y);
			if (vec.x > 0)
				curr.x++;
			else
				curr.x--;
		}
		if (vec.y > 0)
			curr.y++;
		else
			curr.y--;
	}
}

void	bresenham(t_dot *d1, t_dot *d2, t_mlx *mlx)
{
	t_dot	curr;
	t_dot	diff;
	t_dot	vec;

	curr.x = d1->x;
	curr.y = d1->y;
	vec.x = d2->x - d1->x;
	vec.y = d2->y - d1->y;
	vec.color = d1->color;
	diff.x = abs(vec.x);
	diff.y = abs(vec.y);
	diff.color = d2->color;
	if (diff.x >= diff.y)
		_bresenham_x(curr, diff, vec, mlx);
	else
		_bresenham_y(curr, diff, vec, mlx);
}
