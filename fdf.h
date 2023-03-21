/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:50:53 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/21 19:39:45 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define WINDOW_MAX_HEIGHT 1500
# define WINDOW_MAX_WIDTH 2000
# define WINDOW_MARGIN 200

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		gap;
}	t_vars;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_dot
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_dot;

typedef struct s_mapinfo
{
	int				height;
	int				width;
	struct s_dot	*map;
}	t_mapinfo;

void	bresenhams(t_dot d1, t_dot d2, t_img *img);
void	set_gap(t_vars *vars, t_mapinfo *mapinfo);

void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *x, int *y, double gamma);

int		key_hook(int keycode, t_vars *vars);

int		is_hexnumber(char c);
int		map_color(char *str, t_dot *dot, int *idx);
int		map_atoi(char *str, t_dot *dot, int *idx);
int		get_map(char *filename, t_mapinfo *mapinfo);

void	print_map(t_mapinfo *mapinfo);
void	print_only_z(t_mapinfo *mapinfo);
void	print_xyz(t_mapinfo *mapinfo);

#endif