/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:42:54 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/05 15:25:28 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_hook(void)
{
	exit(0);
	return (0);
}

int	_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_UP)
		((mlx->cam).y) -= 10;
	else if (keycode == KEY_DOWN)
		((mlx->cam).y) += 10;
	else if (keycode == KEY_LEFT)
		((mlx->cam).x) -= 10;
	else if (keycode == KEY_RIGHT)
		((mlx->cam).x) += 10;
	else if (keycode == KEY_C)
		((mlx->cam).color) = (((mlx->cam).color) + 1) % 4;
	set_image(mlx);
	return (0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	else if (keycode == KEY_A)
		((mlx->cam).z_angle) -= 5;
	else if (keycode == KEY_D)
		((mlx->cam).z_angle) += 5;
	else if (keycode == KEY_W)
		((mlx->cam).x_angle) += 5;
	else if (keycode == KEY_S)
		((mlx->cam).x_angle) -= 5;
	else if (keycode == KEY_H)
		((mlx->cam).h) += 0.5;
	else if (keycode == KEY_J)
		((mlx->cam).h) -= 0.5;
	return (_key_hook(keycode, mlx));
}

int	mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_SCROLL_UP)
		((mlx->cam).big) += 0.1;
	else if (keycode == MOUSE_SCROLL_DOWN)
	{
		if ((mlx->cam).big > 0.1)
			((mlx->cam).big) -= 0.1;
	}
	set_image(mlx);
	return (0);
}
