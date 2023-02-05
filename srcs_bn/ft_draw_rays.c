// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_draw_rays.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/01/07 23:21:16 by sharrach          #+#    #+#             */
// /*   Updated: 2023/01/30 13:06:45 by sharrach         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/cub3d.h"

// static void	DDA(t_data *data, t_pos fp, t_pos lp)
// {
// 	t_intpos	dist;
// 	t_pos		inc;
// 	t_pos		cord;
// 	int			steps;
// 	int			i;

// 	fp.x *= TILE_SIZE;
// 	lp.x *= TILE_SIZE;
// 	fp.y *= TILE_SIZE;
// 	lp.y *= TILE_SIZE;
// 	dist.x = lp.x - fp.x;
// 	dist.y = lp.y - fp.y;
// 	if (abs(dist.x) > abs(dist.y))
// 		steps = abs(dist.x);
// 	else
// 		steps = abs(dist.y);
// 	inc.x = dist.x / (float)steps;
// 	inc.y = dist.y / (float)steps;
// 	cord.x = fp.x;
// 	cord.y = fp.y;
// 	i = 0;
// 	while (i <= steps) 
// 	{
// 		ft_put_pixel(&data->image, round(cord.x), round(cord.y), 0x000000);
// 		cord.x += inc.x; 
// 		cord.y += inc.y; 
// 		i++;
// 	}
// }

// t_pos	ft_get_wall(t_data *data, float angle)
// {
// 	t_pos	v_inters;
// 	t_pos	h_inters;
// 	t_pos	diff;

// 	v_inters = ft_wall_vdistance(data->player.pos, angle);
// 	diff = ft_wall_vdistance(v_inters, angle);
// 	diff.x -= v_inters.x;
// 	diff.y -= v_inters.y;
// 	while ((diff.x || diff.y)
// 		&& (int)v_inters.y >= 0 && (int)v_inters.y < (int)ft_arrlen(data->map)
// 		&& (int)v_inters.x >= 0 && (int)v_inters.x < (int)ft_strlen(data->map[(int)v_inters.y])
// 		&& data->map[(int)v_inters.y][(int)v_inters.x] != '1')
// 	{
// 		v_inters.x += diff.x;
// 		v_inters.y += diff.y;
// 	}
// 	h_inters = ft_wall_hdistance(data->player.pos, angle);
// 	diff = ft_wall_hdistance(h_inters, angle);
// 	diff.x -= h_inters.x;
// 	diff.y -= h_inters.y;
// 	while ((diff.x || diff.y)
// 		&& (int)h_inters.y >= 0 && (int)h_inters.y < (int)ft_arrlen(data->map)
// 		&& (int)h_inters.x >= 0 && (int)h_inters.x < (int)ft_strlen(data->map[(int)h_inters.y])
// 		&& data->map[(int)h_inters.y][(int)h_inters.x] != '1')
// 	{
// 		h_inters.x += diff.x;
// 		h_inters.y += diff.y;
// 	}
// 	if (ft_distance(data->player.pos, h_inters) < ft_distance(data->player.pos, v_inters))
// 		return (h_inters);
// 	return (v_inters);
// }

// void	ft_draw_rays(t_data *data)
// {
// 	int		rays;
// 	float	sight;
// 	t_pos	wall;

// 	rays = 0;
// 	sight = data->player.sight - PI / 6;
// 	while (rays < 60)
// 	{
// 		wall = ft_get_wall(data, sight);
// 		DDA(data, data->player.pos, wall);
// 		sight += (PI / 180);
// 		rays++;
// 	}
// }
