/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:03:00 by sharrach          #+#    #+#             */
/*   Updated: 2023/02/06 18:51:27 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move_player(t_data *data, float sight)
{
	float	tmp;
	float	tmp1;
	float	wall_dis;

	tmp = data->player.pos.y + sin(sight) * 0.1;
	tmp1 = data->player.pos.x + cos(sight) * 0.1;
	wall_dis = ft_get_wall2(data, sight);
	if (tmp > wall_dis || tmp1 > wall_dis)
	{data->player.pos.y = tmp;
	data->player.pos.x = tmp1;}
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
