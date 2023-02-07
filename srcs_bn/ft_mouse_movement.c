/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:02:46 by sharrach          #+#    #+#             */
/*   Updated: 2023/02/07 14:44:39 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_mouse_movement(t_data *data)
{
	int				x;
	int				y;
	static int		ox;

	mlx_mouse_get_pos(data->window, &x, &y);
	(void)y;
	if (ox == 0)
		ox = x;
	if (x - ox > 0)
		data->player.sight += 0.05;
	else if (x - ox < 0)
		data->player.sight -= 0.05;
	ox = x;
}
