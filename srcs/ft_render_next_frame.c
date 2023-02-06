/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_next_frame.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:43:53 by sharrach          #+#    #+#             */
/*   Updated: 2023/02/06 12:01:37 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_render_next_frame(t_data *data)
{
	ft_get_player_sight(data);
	ft_floor_ceilling_color(data);
	ft_draw_walls(data);
	mlx_put_image_to_window(data->mlx, data->window, data->image.img, 0, 0);
	return (0);
}
