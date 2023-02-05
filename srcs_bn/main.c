/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:43:30 by iellyass          #+#    #+#             */
/*   Updated: 2023/02/05 22:54:54 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	ft_mlx_loop(t_data data)
{
	data.window = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cub3d");
	if (!data.window)
		return (EXIT_FAILURE);
	data.image.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.image.img)
		return (EXIT_FAILURE);
	data.image.width = WIDTH;
	data.image.height = HEIGHT;
	data.image.addr = (int *)mlx_get_data_addr(data.image.img,
			&data.image.bits_per_pixel, &data.image.line_length,
			&data.image.endian);
	mlx_hook(data.window, 2, 1L << 0, ft_key_press, &data);
	mlx_loop_hook(data.mlx, ft_render_next_frame, &data);
	mlx_hook(data.window, 3, 1L << 1, ft_key_free, &data);
	mlx_hook(data.window, 17, 0, ft_exit_program, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}

int	main(int ac, char *av[])
{
	t_data	data;
	char	*file;

	if (ac != 2)
		return (printf("Error\nInvalid argument\n"), EXIT_FAILURE);
	file = ft_strrchr(av[1], '.');
	if (!file || ft_strcmp(file, ".cub") != 0)
		return (printf("Error\nInvalid file name.\n"), EXIT_FAILURE);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (EXIT_FAILURE);
	if (!ft_read_map(&data, av[1]))
		return (EXIT_FAILURE);
	ft_mlx_loop(data);
	return (EXIT_SUCCESS);
}
