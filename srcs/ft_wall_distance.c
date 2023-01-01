/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:04:14 by sharrach          #+#    #+#             */
/*   Updated: 2023/01/01 18:21:13 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_pos    ft_wall_vdistance(t_pos pos, float angle)
{
	if (angle < PI_2 || angle > 3 * PI_2)
	{
		pos.x += (floor(pos.x) + 1) - pos.x;
		pos.y += tan(angle) * pos.x;
	}
	else
	{
		pos.x -= pos.x - floor(pos.x);
		pos.y -= tan(angle) * pos.x;
	}
	return (pos);
}

t_pos    ft_wall_hdistance(t_pos pos, float angle)
{
	if (angle > PI && angle < 2 * PI)
	{
		pos.y -= pos.y - floor(pos.y);
		pos.x -= pos.y / tan(angle);
	}
	else
	{
		pos.y += (floor(pos.y) + 1) - pos.y;
		pos.x += pos.y / tan(angle);
	}
	return (pos);
}
