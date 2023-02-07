/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_ceilling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:19:21 by sharrach          #+#    #+#             */
/*   Updated: 2023/02/07 13:41:22 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static unsigned long	rgb(int rgb[3])
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	ft_floor_ceilling_color(t_data *data)
{
	t_intpos	cord;

	cord.y = 0;
	while (cord.y < HEIGHT)
	{
		cord.x = 0;
		while (cord.x < WIDTH)
		{
			if (cord.y < HEIGHT / 2)
				ft_put_pixel(&data->image, cord.x, cord.y, rgb(data->ce));
			else
				ft_put_pixel(&data->image, cord.x, cord.y, rgb(data->fl));
			cord.x++;
		}
		cord.y++;
	}
}
