/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:56:32 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/23 16:24:37 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "minilibx/mlx.h"

# define WINDOW_MAX_HEIGHT 1500
# define WINDOW_MAX_WIDTH 2000
# define WINDOW_MARGIN 200

typedef struct s_dot
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_dot;

typedef struct s_map
{
	int				height;
	int				width;
	struct s_dot	*map;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		gap;
}	t_mlx;

t_map	*get_map(char *filename);
void	set_gap(t_map *map, t_mlx *mlx);
void	set_coordinate(t_map *map, t_mlx *mlx);
void	set_image(t_map *map, t_img *img, t_mlx *mlx);
void	draw_image(t_map *map, t_img *img);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	bresenham(t_dot *d1, t_dot *d2, t_img *img);

int		get_dot_color(char *line, t_dot *dot, int *idx);
int		map_atoi(char *line, t_dot *dot, int *idx);

int		free_map(t_map *map);
int		is_in_string(char c, const char *str);
int		map_widthjoin(t_map *map);

int		key_hook(int keycode, t_mlx *mlx);

void	print_map(t_map *map);
void	print_xy(t_map *map);
void	print_dot(t_dot *dot);
void	print_info(t_map *map, t_mlx *mlx, t_img *img);

#endif
