/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:03:00 by sharrach          #+#    #+#             */
/*   Updated: 2023/01/14 19:56:32 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move_player(t_data *data)
{
	float	sight;
	float	tmp;
	float	tmp1;

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
	tmp = data->player.pos.y + sin(sight) * 0.01;
	tmp1 = data->player.pos.x + cos(sight) * 0.01;
	if (data->map[(int)tmp][(int)tmp1] != '1')
	{
		data->player.pos.y = tmp;
		data->player.pos.x = tmp1;
	}
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
	else if (keycode == KEY_LEFT)
		data->player.sight -= 0.05;
	else if (keycode == KEY_RIGHT)
		data->player.sight += 0.05;
	else if (keycode == KEY_ESC)
	{
		printf("Game Closed");
		exit(0);
	}
	return (0);
}

int ft_key_free(int keycode, t_data *data)
{

	if (keycode == KEY_W || keycode == KEY_UP)
		data->vars.w_var = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		data->vars.s_var = 0;
	else if (keycode == KEY_D)
		data->vars.d_var = 0;
	else if (keycode == KEY_A)
		data->vars.a_var = 0;
	return (0);
}
