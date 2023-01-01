/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:45:30 by sharrach          #+#    #+#             */
/*   Updated: 2023/01/01 20:41:10 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	my_mlx_pixel_put(t_img *image, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	ft_draw_player(t_data *data, float x, float y, int color)
{
	int i;
	int j;

	j = y * 30 - 5;
	while (j < (y * 30) + 5)
	{
		i = x * 30 - 5;
		while (i < (x * 30) + 5)
		{
			my_mlx_pixel_put(&data->image, i, j, color);
			i++;
		}
		j++;
	}
}

static void	ft_draw_square(t_data *data, int x, int y, int color)
{
	int i;
	int j;

	j = y * 30;
	while (j < (y * 30) + 30 - 1)
	{
		i = x * 30;
		while (i < (x * 30) + 30 - 1)
		{
			my_mlx_pixel_put(&data->image, i, j, color);
			i++;
		}
		j++;
	}
}

float	ft_distance(t_pos pos1, t_pos pos2)
{
	float	distance;

	distance = sqrt(pow(pos2.x - pos1.x, 2) + pow(pos2.y - pos1.y, 2));
	return (distance);
}

void	ft_draw_rays(t_data *data)
{
	t_pos	pos;
	t_pos	v_inters;
	t_pos	h_inters;

	pos.y = data->player.pos.y;
	pos.x = data->player.pos.x;
	// printf("222 %f %f - %c\n", pos.y, pos.x, data->map[(int)pos.y][(int)pos.x]);
	while (data->map[(int)pos.y][(int)pos.x] != '1' )
	{
		v_inters = ft_wall_vdistance(pos, data->player.sight);
		h_inters = ft_wall_hdistance(pos, data->player.sight);
		if (ft_distance(data->player.pos, v_inters) > ft_distance(data->player.pos, h_inters))
		{
			pos.y = h_inters.y;
			pos.x = h_inters.x;
			printf("1 %f %f - %c\n", pos.y, pos.x, data->map[(int)pos.y][(int)pos.x]);
		}
		else if (ft_distance(data->player.pos, v_inters) < ft_distance(data->player.pos, h_inters))
		{
			pos.y = v_inters.y;
			pos.x = v_inters.x;
			printf("2 %f %f - %c\n", pos.y, pos.x, data->map[(int)pos.y][(int)pos.x]);
		}
	}
	ft_draw_player(data, pos.x, pos.y, 0xff0000);
}

void	ft_draw_minimap(t_data *data)
{
	int x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				ft_draw_square(data, x, y, 0xeb4034);
			if (ft_strchr("0NSWE", data->map[y][x]))
				ft_draw_square(data, x, y, 0xbfbf9f);
			if (data->map[y][x] == ' ')
				ft_draw_square(data, x, y, 0x1752e8);
			x++;
		}
		y++;
	}
	ft_draw_player(data, data->player.pos.x, data->player.pos.y, 0x12c912);
	ft_draw_rays(data);
}
