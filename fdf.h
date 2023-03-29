/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:56:32 by jeelee            #+#    #+#             */
/*   Updated: 2023/03/29 18:14:13 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "minilibx/mlx.h"

# define WINDOW_MAX_HEIGHT 1500
# define WINDOW_MAX_WIDTH 2000
# define WINDOW_MARGIN 200

# define MOUSE_LEFT_BUTTON 1
# define MOUSE_RIGHT_BUTTON 2
# define MOUSE_SCROLL_BUTTON 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ESC_KEY 53

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
	int				high;
	struct s_dot	*map;
	struct s_dot	*mapinit;
}	t_map;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}	t_img;

typedef struct s_cam
{
	int		x;
	int		y;
	int		z;
	double	x_angle;
	double	y_angle;
	double	z_angle;
}	t_cam;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	int				height;
	int				width;
	int				gap;
	struct s_dot	base;
	struct s_img	img;
	struct s_map	*map;
	struct s_cam	cam;
}	t_mlx;

t_map	*get_map(char *filename);

int		get_dot_color(char *line, t_dot *dot, int *idx);
int		map_atoi(char *line, t_dot *dot, int *idx);

void	set_size(t_mlx *mlx);
t_dot	set_coordinate(int gap, t_map *map);

int		free_map(t_map *map);
void	map_init(t_map *map);
int		is_in_string(char c, const char *str);
int		map_widthjoin(t_map *map);

int		key_hook(int keycode, t_mlx *mlx);

void	print_map(t_map *map);
void	print_xy(t_map *map);
void	print_color(t_map *map);
void	print_info(t_mlx *mlx);

#endif
