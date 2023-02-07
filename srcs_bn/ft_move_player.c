/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:03:00 by sharrach          #+#    #+#             */
/*   Updated: 2023/02/07 15:02:06 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	ft_move_player(t_data *data, float sight)
{
	t_pos	wall;
	t_pos	pos;

	pos.y = data->player.pos.y + sin(sight) * 0.1;
	pos.x = data->player.pos.x + cos(sight) * 0.1;
	wall = ft_get_wall(data, sight, NULL);
	if (pos.y < ft_arrlen(data->map)
		&& pos.x < (float)ft_strlen(data->map[(int)pos.y])
		&& data->map[(int)pos.y][(int)pos.x] != '1'
		&& ft_distance(data->player.pos, wall)
		> ft_distance(data->player.pos, pos))
	{
		data->player.pos.y = pos.y;
		data->player.pos.x = pos.x;
	}
}

void	ft_get_player_sight(t_data *data)
{
	float	sight;

	if (data->vars.l_var == 1)
		data->player.sight -= 0.03;
	else if (data->vars.r_var == 1)
		data->player.sight += 0.03;
	if (data->vars.w_var == 1 && data->vars.a_var == 1)
		sight = data->player.sight - PI_2 / 2;
	else if (data->vars.w_var == 1 && data->vars.d_var == 1)
		sight = data->player.sight + PI_2 / 2;
	else if (data->vars.s_var == 1 && data->vars.a_var == 1)
		sight = data->player.sight - 3 * PI / 4;
	else if (data->vars.s_var == 1 && data->vars.d_var == 1)
		sight = data->player.sight + 3 * PI / 4;
	else if (data->vars.w_var == 1)
		sight = data->player.sight;
	else if (data->vars.s_var == 1)
		sight = data->player.sight - PI;
	else if (data->vars.d_var == 1)
		sight = data->player.sight + PI_2;
	else if (data->vars.a_var == 1)
		sight = data->player.sight - PI_2;
	else
		return ;
	ft_move_player(data, sight);
}

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		data->vars.w_var = 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		data->vars.s_var = 1;
	else if (keycode == KEY_D)
		data->vars.d_var = 1;
	else if (keycode == KEY_A)
		data->vars.a_var = 1;
	else if (keycode == KEY_RIGHT)
		data->vars.r_var = 1;
	else if (keycode == KEY_LEFT)
		data->vars.l_var = 1;
	else if (keycode == KEY_ESC)
		ft_exit_program(data);
	return (0);
}

int	ft_key_free(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		data->vars.w_var = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		data->vars.s_var = 0;
	else if (keycode == KEY_D)
		data->vars.d_var = 0;
	else if (keycode == KEY_A)
		data->vars.a_var = 0;
	else if (keycode == KEY_RIGHT)
		data->vars.r_var = 0;
	else if (keycode == KEY_LEFT)
		data->vars.l_var = 0;
	return (0);
}
