/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:56:32 by jeelee            #+#    #+#             */
/*   Updated: 2023/04/04 18:19:43 by jeelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "minilibx/mlx.h"

# define ANSI_RES "\e[0;0m"
# define ANSI_BOL "\e[0;1m"
# define ANSI_ITA "\e[0;3m"
# define ANSI_BLC "\e[0;30m"
# define ANSI_RED "\e[0;31m"
# define ANSI_GRE "\e[0;32m"
# define ANSI_YEL "\e[0;33m"
# define ANSI_BLU "\e[0;34m"
# define ANSI_MAG "\e[0;35m"
# define ANSI_CYA "\e[0;36m"

# define WINDOW_MAX_HEIGHT 1800
# define WINDOW_MAX_WIDTH 2000
# define WINDOW_MARGIN 200

# define X_EVENT_KEY_EXIT 17

# define MOUSE_LEFT_BUTTON 1
# define MOUSE_RIGHT_BUTTON 2
# define MOUSE_SCROLL_BUTTON 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_H 4
# define KEY_J 38
# define ESC_KEY 53

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

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
	struct s_dot	*mid;
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
	double	h;
	double	big;
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
	struct s_img	img;
	struct s_map	*map;
	struct s_cam	cam;
}	t_mlx;

t_map	*get_map(char *filename);

int		get_dot_color(char *line, t_dot *dot, int *idx);
int		map_atoi(char *line, t_dot *dot, int *idx);

void	rotate_x(t_dot *dot, double angle, t_dot *base);
void	rotate_y(t_dot *dot, double angle, t_dot *base);
void	rotate_z(t_dot *dot, double angle, t_dot *base);
void	scale_dot(t_dot *dot, double big);
void	set_size(t_mlx *mlx);

void	set_coordinate(t_mlx *mlx);
void	update_coordinate(t_mlx *mlx);

t_dot	get_min(t_map *map);
t_dot	get_max(t_map *map);
void	set_image(t_mlx *mlx);
void	draw_image(t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *mlx, t_dot dot, int color);
int		get_color(int pre_color, int next_color, int i, int size);
void	bresenham(t_dot *d1, t_dot *d2, t_mlx *mlx);

int		key_hook(int keycode, t_mlx *mlx);
int		exit_hook(void);
int		mouse_hook(int keycode, int x, int y, t_mlx *mlx);

int		free_map(t_map *map);
void	cam_init(t_cam *cam);
void	map_init(t_map *map);
void	map_all_init(t_map *map);
int		is_in_string(char c, const char *str);
int		map_widthjoin(t_map *map);
int		error_massage(char *message, int ret);

#endif
