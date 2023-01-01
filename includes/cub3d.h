/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:35:01 by sharrach          #+#    #+#             */
/*   Updated: 2023/01/01 18:22:08 by sharrach         ###   ########.fr       */
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

# define KEY_ESC	65307
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_W		119
# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

# define PI			3.14159265358979323846
# define PI_2		1.57079632679489661923

typedef struct s_img
{
	void	*img;
	char	*addr;
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
}	t_vars;

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

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
int 	ft_render_next_frame(t_data *data);
int		ft_key_press(int keycode, t_data *data);
int		ft_key_free(int keycode, t_data *data);
void	ft_move_player(t_data *data);
t_pos    ft_wall_vdistance(t_pos pos, float angle);
t_pos    ft_wall_hdistance(t_pos pos, float angle);

#endif