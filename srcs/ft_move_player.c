/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:03:00 by sharrach          #+#    #+#             */
/*   Updated: 2023/01/01 16:19:57 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move_player(t_data *data)
{
	float	sight;

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
	data->player.pos.y += sin(sight) * 0.01;
	data->player.pos.x += cos(sight) * 0.01;
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
		data->player.sight -= 0.1;
	else if (keycode == KEY_RIGHT)
		data->player.sight += 0.1;
	// else if (keycode == KEY_ESC)
	// {
	// 	ft_printf("Game Closed");
	// 	exit_program (data);
	// }
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
