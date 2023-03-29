/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:40:58 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/30 03:08:18 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_color	sep_color(int pre_color, int next_color, int size)
{
	t_color	rgb;

	rgb.r = abs((next_color >> 16) - (pre_color >> 16)) / (size - 1);
	rgb.g = abs((next_color >> 8 & 0xFF) - \
		(pre_color >> 8 & 0xFF)) / (size - 1);
	rgb.b = abs((pre_color & 0xFF) - (pre_color & 0xFF)) / (size - 1);
	return (rgb);
}

int	get_color(int pre_color, int next_color, int i, int size)
{
	int		ret;
	t_color	rgb;

	ret = pre_color;
	if (i > size / 2)
	{
		rgb = sep_color(pre_color, next_color, size);
		if ((next_color >> 16) > (pre_color >> 16))
			ret += (rgb.r * i) << 16;
		else
			ret -= (rgb.r * i) << 16;
		if ((next_color >> 8 & 0xFF) > (pre_color >> 8 & 0xFF))
			ret += (rgb.g * i) << 8;
		else
			ret -= (rgb.g * i) << 8;
		if ((pre_color & 0xFF) > (next_color & 0xFF))
			ret += rgb.b * i;
		else
			ret -= rgb.b * i;
	}
	return (ret);
}
