/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:40:58 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/29 18:42:08 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	sep_color(int pre_color, int next_color, int size, t_color *rgb)
{
	t_color	start;

	rgb->r = abs((next_color >> 16) - (pre_color >> 16)) / size;
	rgb->g = abs((next_color >> 8 & 0xFF) - (pre_color >> 8 & 0xFF)) / size;
	rgb->b = abs((pre_color & 0xFF) - (pre_color & 0xFF)) / size;
	start.r = pre_color >> 16;
	start.g = pre_color >> 8 & 0xFF;
	start.b = pre_color & 0xFF;
	return (start);
}

int	get_color(int pre_color, int next_color, int i, int size)
{
	t_color	start;
	t_color	rgb;

	start = sep_color(next_color, pre_color, size, &rgb);
	if (next_color - pre_color > 0)
	{
		return (((start.r + (rgb.r * i)) << 16) + \
			((start.g + (rgb.g * i)) << 8) + (start.b + (rgb.b * i)));
	}
	else if (next_color - pre_color < 0)
	{
		return (((start.r + (rgb.r * (size - i))) << 16) + \
			((start.g + (rgb.g * (size - i))) << 8) + \
				(start.b + (rgb.b * (size - i))));
	}
	else
		return (next_color);
}
