/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:43:49 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/21 22:14:51 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_img		img;
	t_vars		vars;
	t_mapinfo	mapinfo;

	if (ac != 2)
		return (-1);
	if (get_map(av[1], &mapinfo) == -1)
		return (-1);
	set_gap(&vars, &mapinfo);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "fdf");
	mlx_key_hook(vars.win, key_hook, &vars);
	img.img = mlx_new_image(vars.mlx, 600, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_size, &img.endian);
	draw_map(&mapinfo, &vars, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	if (mapinfo.map)
		free(mapinfo.map);
	return (0);
}
