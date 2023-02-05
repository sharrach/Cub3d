/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:04:14 by sharrach          #+#    #+#             */
/*   Updated: 2023/02/05 22:06:33 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

t_pos	ft_wall_vdistance(t_pos pos, float angle)
{
	while (angle >= 2 * PI)
		angle -= 2 * PI;
	while (angle < 0)
		angle += 2 * PI;
	if (angle > PI_2 && angle < 3 * PI_2)
	{
		pos.y -= tan(angle) * (pos.x - floor(pos.x));
		pos.x -= pos.x - floor(pos.x);
		pos.x -= 0.0001;
	}
	else
	{
		pos.y += tan(angle) * ((floor(pos.x) + 1) - pos.x);
		pos.x += (floor(pos.x) + 1) - pos.x;
	}
	return (pos);
}

t_pos	ft_wall_hdistance(t_pos pos, float angle)
{
	while (angle >= 2 * PI)
		angle -= 2 * PI;
	while (angle < 0)
		angle += 2 * PI;
	if (angle > PI && angle < 2 * PI)
	{
		pos.x -= (pos.y - floor(pos.y)) / tan(angle);
		pos.y -= pos.y - floor(pos.y);
		pos.y -= 0.0001;
	}
	else
	{
		pos.x += ((floor(pos.y) + 1) - pos.y) / tan(angle);
		pos.y += (floor(pos.y) + 1) - pos.y;
	}
	return (pos);
}
