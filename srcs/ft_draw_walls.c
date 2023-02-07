/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:57:59 by sharrach          #+#    #+#             */
/*   Updated: 2023/02/07 13:40:17 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_draw_wall(t_data *data, t_pos wall, float angle, int var)
{
	static t_elmnt	elmnt;
	float			distance;

	while (angle >= 2 * PI)
		angle -= 2 * PI;
	while (angle < 0)
		angle += 2 * PI;
	distance = ft_distance(data->player.pos, wall)
		* cos(data->player.sight - angle);
	elmnt.dims.height = HEIGHT / distance;
	elmnt.dims.width = WIDTH / (FOV / 0.1);
	elmnt.pos.y = (HEIGHT - elmnt.dims.height) / 2;
	elmnt.wall.x = wall.x;
	elmnt.wall.y = wall.y;
	if ((angle > PI && angle < 2 * PI) && var == 1)
		ft_draw_rect(data, elmnt, data->no, var);
	else if ((angle < PI_2 || angle > 3 * PI_2) && var == 2)
		ft_draw_rect(data, elmnt, data->ea, var);
	else if ((angle < PI && angle > 0) && var == 1)
		ft_draw_rect(data, elmnt, data->so, var);
	else if ((angle > PI_2 && angle < 3 * PI_2) && var == 2)
		ft_draw_rect(data, elmnt, data->we, var);
	elmnt.pos.x += elmnt.dims.width;
	if (elmnt.pos.x >= WIDTH)
		elmnt.pos.x = 0;
}

static t_pos	ft_get_v_inters(t_data *data, float angle)
{
	t_pos	diff;
	t_pos	v_inters;

	v_inters = ft_wall_vdistance(data->player.pos, angle);
	diff = ft_wall_vdistance(v_inters, angle);
	diff.x -= v_inters.x;
	diff.y -= v_inters.y;
	while ((diff.x || diff.y)
		&& (int)v_inters.y >= 0 && (int)v_inters.y < (int)ft_arrlen(data->map)
		&& (int)v_inters.x >= 0
		&& (int)v_inters.x < (int)ft_strlen(data->map[(int)v_inters.y])
		&& data->map[(int)v_inters.y][(int)v_inters.x] != '1')
	{
		v_inters.x += diff.x;
		v_inters.y += diff.y;
	}
	return (v_inters);
}

static t_pos	ft_get_h_inters(t_data *data, float angle)
{
	t_pos	diff;
	t_pos	h_inters;

	h_inters = ft_wall_hdistance(data->player.pos, angle);
	diff = ft_wall_hdistance(h_inters, angle);
	diff.x -= h_inters.x;
	diff.y -= h_inters.y;
	while ((diff.x || diff.y)
		&& (int)h_inters.y >= 0 && (int)h_inters.y < (int)ft_arrlen(data->map)
		&& (int)h_inters.x >= 0
		&& (int)h_inters.x < (int)ft_strlen(data->map[(int)h_inters.y])
		&& data->map[(int)h_inters.y][(int)h_inters.x] != '1')
	{
		h_inters.x += diff.x;
		h_inters.y += diff.y;
	}
	return (h_inters);
}

static t_pos	ft_get_wall(t_data *data, float angle, int *var)
{
	if (ft_distance(data->player.pos, ft_get_h_inters(data, angle))
		< ft_distance(data->player.pos, ft_get_v_inters(data, angle)))
	{
		*var = 1;
		return (ft_get_h_inters(data, angle));
	}
	*var = 2;
	return (ft_get_v_inters(data, angle));
}

void	ft_draw_walls(t_data *data)
{
	float	rays;
	float	sight;
	t_pos	wall;
	int		var;

	rays = 0;
	sight = data->player.sight - (FOV / 2) * (PI / 180);
	while (rays < FOV)
	{
		wall = ft_get_wall(data, sight, &var);
		ft_draw_wall(data, wall, sight, var);
		sight += 0.1 * (PI / 180);
		rays += 0.1;
	}
}
