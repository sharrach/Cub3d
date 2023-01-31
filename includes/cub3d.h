/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:35:01 by sharrach          #+#    #+#             */
/*   Updated: 2023/01/31 14:33:12 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <errno.h>
// #include <graphics.h>


// # define KEY_ESC	65307
// # define KEY_A		97
// # define KEY_S		115
// # define KEY_D		100
// # define KEY_W		119
# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT	123
# define KEY_UP		126
# define KEY_RIGHT	124
# define KEY_DOWN	125

# define TILE_SIZE	8
# define FOV		60
# define WIDTH		1080
# define HEIGHT		720

# define PI			3.14159265358979323846
# define PI_2		1.57079632679489661923

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_vars
{
	int	s_var;
	int	d_var;
	int	a_var;
	int	w_var;
	int l_var;
	int r_var;
}	t_vars;

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_dims
{
	float	width;
	float	height;
}	t_dims;

typedef struct s_elmnt
{
	t_pos	pos;
	t_pos	wall;
	t_dims	dims;
}	t_elmnt;


typedef struct s_intpos
{
	int	x;
	int	y;
}	t_intpos;

typedef struct s_player
{
	t_pos	pos;
	float	sight;
}	t_player;

typedef struct s_data
{
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	int			fl[3];
	int			ce[3];
	char		**map;
	void		*mlx;
	void		*window;
	t_img		image;
	t_player	player;
	t_vars		vars;
}	t_data;

int		ft_read_map(t_data *data, char *file);
void	ft_draw_minimap(t_data *data);
int		ft_render_next_frame(t_data *data);
int		ft_key_press(int keycode, t_data *data);
int		ft_key_free(int keycode, t_data *data);
void	ft_get_player_sight(t_data *data);
t_pos	ft_wall_vdistance(t_pos pos, float angle);
t_pos	ft_wall_hdistance(t_pos pos, float angle);
void	ft_put_pixel(t_img *image, int x, int y, int color);
void	ft_draw_walls(t_data *data);
float	ft_distance(t_pos pos1, t_pos pos2);
void	ft_draw_rays(t_data *data);
void	ft_floor_ceilling_color(t_data *data);
//utils
int		ft_is_init(t_data *data);
void	ft_init_data(t_data *data);
int		ft_is_number(char *str);
int		ft_map_closed(t_data *data);
int		ft_get_image(t_data *data, char **usb);
int		ft_get_map(t_data *data, int fd);
int		ft_get_colors(t_data *data, char **usb);
void	ft_draw_rect(t_data *data, t_elmnt elmnt, t_img img, int var);

#endif