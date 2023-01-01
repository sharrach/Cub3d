/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_next_frame.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:43:53 by sharrach          #+#    #+#             */
/*   Updated: 2023/01/01 18:21:33 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_render_next_frame(t_data *data)
{
	ft_move_player(data);
	ft_draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->window, data->image.img, 0, 0);
	return (0);
}
