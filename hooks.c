/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:35:32 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/27 10:56:39 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	key_hook(int keycode, t_param *param)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window((param->mlx).mlx, (param->mlx).win);
		exit(0);
	}
	else if (keycode == KEY_A)
		(((param->mlx).cam).z_angle)--;
	else if (keycode == KEY_D)
		(((param->mlx).cam).z_angle)++;
	else if (keycode == KEY_W)
		(((param->mlx).cam).x_angle)++;
	else if (keycode == KEY_S)
		(((param->mlx).cam).x_angle)--;
	set_image(param->map, &(param->img), &(param->mlx));
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_param *param)
{
	if (keycode == MOUSE_LEFT_BUTTON)
		printf("Hello LIFT (%d, %d)\n", x, y);
	else if (keycode == MOUSE_RIGHT_BUTTON)
		printf("HELLO RIGHT (%d, %d)\n", x, y);
	else if (keycode == MOUSE_SCROLL_UP)
		((param->mlx).gap)++;
	else if (keycode == MOUSE_SCROLL_DOWN)
	{
		if ((param->mlx).gap > 0)
			((param->mlx).gap)--;
	}
	set_image(param->map, &(param->img), &(param->mlx));
	return (0);
}
