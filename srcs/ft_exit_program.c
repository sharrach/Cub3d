/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:10:49 by sharrach          #+#    #+#             */
/*   Updated: 2023/02/04 15:53:17 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_exit_program(t_data *data)
{
	data->map = ft_free2d(data->map);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->no.img);
	mlx_destroy_image(data->mlx, data->ea.img);
	mlx_destroy_image(data->mlx, data->we.img);
	mlx_destroy_image(data->mlx, data->so.img);
	mlx_destroy_image(data->mlx, data->image.img);
	exit (EXIT_SUCCESS);
}
