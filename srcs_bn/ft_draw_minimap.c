/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:45:30 by sharrach          #+#    #+#             */
/*   Updated: 2023/02/04 17:19:36 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_draw_player(t_data *data, t_pos player, int color)
{
	t_intpos	cord;

	cord.y = player.y * TILE_SIZE - 2;
	while (cord.y <= (player.y * TILE_SIZE) + 2)
	{
		cord.x = player.x * TILE_SIZE - 2;
		while (cord.x <= (player.x * TILE_SIZE) + 2)
		{
			ft_put_pixel(&data->image, cord.x, cord.y, color);
			cord.x++;
		}
		cord.y++;
	}
}

static void	ft_draw_square(t_data *data, t_intpos pos, int color)
{
	t_intpos	cord;

	cord.y = pos.y * TILE_SIZE;
	while (cord.y < (pos.y * TILE_SIZE) + TILE_SIZE - 1)
	{
		cord.x = pos.x * TILE_SIZE;
		while (cord.x < (pos.x * TILE_SIZE) + TILE_SIZE - 1)
		{
			ft_put_pixel(&data->image, cord.x, cord.y, color);
			cord.x++;
		}
		cord.y++;
	}
}

float	ft_distance(t_pos pos1, t_pos pos2)
{
	float	distance;

	distance = sqrt(powf(pos2.x - pos1.x, 2) + powf(pos2.y - pos1.y, 2));
	return (distance);
}

void	ft_draw_minimap(t_data *data)
{
	t_intpos	cord;

	cord.y = 0;
	while (data->map[cord.y])
	{
		cord.x = 0;
		while (data->map[cord.y][cord.x])
		{
			if (data->map[cord.y][cord.x] == '1')
				ft_draw_square(data, cord, 0xeb4034);
			if (ft_strchr("0NSWE", data->map[cord.y][cord.x]))
				ft_draw_square(data, cord, 0xbfbf9f);
			if (data->map[cord.y][cord.x] == ' ')
				ft_draw_square(data, cord, 0x1752e8);
			cord.x++;
		}
		cord.y++;
	}
	ft_draw_player(data, data->player.pos, 0x12c912);
	// ft_draw_rays(data);
}