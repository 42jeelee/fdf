/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:43:49 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/21 19:30:20 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draaaaw(t_img *img)
{
	t_dot	d1;
	t_dot	d2;

	d1.x = 10;
	d1.y = 10;
	d2.x = 500;
	d2.y = 300;
	bresenhams(d1, d2, img);
}

int	main(int ac, char **av)
{
	t_img		img;
	t_vars		vars;
	t_mapinfo	mapinfo;

	if (ac != 2)
		return (-1);
	if (get_map(av[1], &mapinfo) == -1)
		return (-1);
	print_xyz(&mapinfo);
	set_gap(&vars, &mapinfo);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "fdf");
	mlx_key_hook(vars.win, key_hook, &vars);
	img.img = mlx_new_image(vars.mlx, 600, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_size, &img.endian);
	draaaaw(&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	if (mapinfo.map)
		free(mapinfo.map);
	return (0);
}
