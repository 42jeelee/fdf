/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:40:58 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/04 21:17:46 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	sep_color(int pre_color, int next_color, int size)
{
	t_color	rgb;

	rgb.r = abs((next_color >> 16) - (pre_color >> 16)) / size;
	rgb.g = abs((next_color >> 8 & 0xFF) - \
		(pre_color >> 8 & 0xFF)) / size;
	rgb.b = abs((next_color & 0xFF) - (pre_color & 0xFF)) / size;
	return (rgb);
}

int	get_color(int pre_color, int next_color, int i, int size)
{
	int		ret;
	t_color	rgb;

	if (i == size)
		return (next_color);
	ret = pre_color;
	rgb = sep_color(pre_color, next_color, size);
	if ((next_color >> 16) > (pre_color >> 16))
		ret += (rgb.r * i) << 16;
	else
		ret -= (rgb.r * i) << 16;
	if ((next_color >> 8 & 0xFF) > (pre_color >> 8 & 0xFF))
		ret += (rgb.g * i) << 8;
	else
		ret -= (rgb.g * i) << 8;
	if ((next_color & 0xFF) > (pre_color & 0xFF))
		ret += rgb.b * i;
	else
		ret -= rgb.b * i;
	return (ret);
}
