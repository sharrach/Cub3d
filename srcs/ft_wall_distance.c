/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:04:14 by sharrach          #+#    #+#             */
/*   Updated: 2023/01/03 22:26:04 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_pos    ft_wall_vdistance(t_pos pos, float angle)
{
	while (angle >= 2 * PI)
		angle -= 2 * PI;
	while (angle < 0)
		angle += 2 * PI;
	printf("v2: %f\n", angle * 180.0 / PI);
	if (angle < PI_2 || angle > 3 * PI_2)
	{
		pos.x += (floor(pos.x) + 1) - pos.x;
		pos.y = pos.y + (tan(angle) * pos.x);
	}
	else
	{
		pos.x -= pos.x - floor(pos.x);
		// pos.x -= 0.000001;
		pos.y -= tan(angle) * pos.x;
	}
	return (pos);
}

t_pos    ft_wall_hdistance(t_pos pos, float angle)
{
	while (angle >= 2 * PI)
		angle -= 2 * PI;
	while (angle < 0)
		angle += 2 * PI;
	// printf("h2: %f\n", angle * 180.0 / PI);
	if (angle > PI && angle < 2 * PI)
	{
		pos.y -= pos.y - floor(pos.y);
		// pos.y -= 0.000001;
		pos.x -= pos.y / tan(angle);
	}
	else
	{
		pos.y += (floor(pos.y) + 1) - pos.y;
		pos.x += pos.y / tan(angle);
	}
	return (pos);
}
