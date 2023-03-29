/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:42:54 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/30 00:47:25 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	else if (keycode == KEY_A)
		((mlx->cam).z_angle)++;
	else if (keycode == KEY_D)
		((mlx->cam).z_angle)--;
	else if (keycode == KEY_W)
		((mlx->cam).x_angle)++;
	else if (keycode == KEY_S)
		((mlx->cam).x_angle)--;
	else if (keycode == KEY_H)
		((mlx->cam).h) += 0.1;
	else if (keycode == KEY_J)
		((mlx->cam).h) -= 0.1;
	set_image(mlx);
	return (0);
}
