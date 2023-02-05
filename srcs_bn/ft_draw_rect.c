/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:11:01 by sharrach          #+#    #+#             */
/*   Updated: 2023/02/05 22:05:42 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_draw_rect(t_data *data, t_elmnt elmnt, t_img img, int var)
{
	t_pos		pos;
	t_pos		cons;
	t_intpos	color;

	cons.x = img.width;
	cons.y = img.height / elmnt.dims.height;
	if (var == 1)
		color.x = (elmnt.wall.x - floor(elmnt.wall.x)) * cons.x;
	else
		color.x = (elmnt.wall.y - floor(elmnt.wall.y)) * cons.x;
	pos.y = fmax(elmnt.pos.y, 0);
	while (pos.y < elmnt.pos.y + elmnt.dims.height && pos.y < HEIGHT)
	{
		color.y = (pos.y - elmnt.pos.y) * cons.y;
		pos.x = fmax(elmnt.pos.x, 0);
		while (pos.x < elmnt.pos.x + elmnt.dims.width && pos.x < WIDTH)
		{
			ft_put_pixel(&data->image, pos.x, pos.y,
				img.addr[img.width * color.y + color.x]);
			pos.x++;
		}
		pos.y++;
	}
}
