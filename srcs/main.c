/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:43:30 by iellyass          #+#    #+#             */
/*   Updated: 2023/01/30 16:06:27 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*free2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free (arr);
	return (NULL);
}

int	exit_program(t_data *data)
{
	data->map = free2d(data->map);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->no.img);
	mlx_destroy_image(data->mlx, data->ea.img);
	mlx_destroy_image(data->mlx, data->we.img);
	mlx_destroy_image(data->mlx, data->so.img);
	mlx_destroy_image(data->mlx, data->image.img);
	exit (EXIT_SUCCESS);
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
	mlx_hook(data.window, 17, 0, exit_program, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
