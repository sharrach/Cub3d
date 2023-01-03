/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:45:30 by sharrach          #+#    #+#             */
/*   Updated: 2023/01/03 22:28:31 by sharrach         ###   ########.fr       */
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
// && printf("%d %d\n", (int)v_inters.x, (int)ft_strlen(data->map[(int)v_inters.y]))
// && printf("%d %d\n", (int)v_inters.x, (int)ft_strlen(data->map[(int)v_inters.y]))
// printf("%d %d\n", (int)v_inters.y, (int)ft_arrlen(data->map))
// && (printf("%d %d\n", (int)h_inters.y, (int)ft_arrlen(data->map))


float	ft_distance(t_pos pos1, t_pos pos2)
{
	float	distance;

	distance = sqrt(pow(pos2.x - pos1.x, 2) + pow(pos2.y - pos1.y, 2));
	return (distance);
}

void	ft_draw_rays(t_data *data)
{
	t_pos	v_inters;
	t_pos	h_inters;
	t_pos	diff;

	v_inters = ft_wall_vdistance(data->player.pos, data->player.sight);
	diff = ft_wall_vdistance(v_inters, data->player.sight);
	diff.x -= v_inters.x;
	diff.y -= v_inters.y;
	while ((diff.x || diff.y)
		&& (int)v_inters.y >= 0 && (int)v_inters.y < (int)ft_arrlen(data->map)
		&& (int)v_inters.x >= 0 && (int)v_inters.x < (int)ft_strlen(data->map[(int)v_inters.y])
		&& data->map[(int)v_inters.y][(int)v_inters.x] != '1')
	{
		v_inters.x += diff.x;
		v_inters.y += diff.y;
	}
	h_inters = ft_wall_hdistance(data->player.pos, data->player.sight);
	diff = ft_wall_hdistance(h_inters, data->player.sight);
	diff.x -= h_inters.x;
	diff.y -= h_inters.y;
	while ((diff.x || diff.y)
		&& (int)h_inters.y >= 0 && (int)h_inters.y < (int)ft_arrlen(data->map)
		&& (int)h_inters.x >= 0 && (int)h_inters.x < (int)ft_strlen(data->map[(int)h_inters.y])
		&& data->map[(int)h_inters.y][(int)h_inters.x] != '1')
	{
		h_inters.x += diff.x;
		h_inters.y += diff.y;
	}
	if (ft_distance(data->player.pos, h_inters) < ft_distance(data->player.pos, v_inters))
	{
		// printf("h %f %f - %c\n", h_inters.y, h_inters.x, data->map[(int)h_inters.y][(int)h_inters.x]);
		ft_draw_player(data, h_inters.x, h_inters.y, 0x000000);
	}
	else
	{
		// printf("v %f %f - %c\n", v_inters.y, v_inters.x, data->map[(int)v_inters.y][(int)v_inters.x]);
		ft_draw_player(data, v_inters.x, v_inters.y, 0x000000);
	}
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
