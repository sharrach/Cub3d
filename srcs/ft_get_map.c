/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:41:56 by sharrach          #+#    #+#             */
/*   Updated: 2023/02/06 14:58:52 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_get_colors(t_data *data, char **usb)
{
	char	**clr;

	clr = ft_split(usb[1], ',');
	if (!clr || ft_arrlen(clr) != 3 || !ft_is_number(clr[0])
		|| !ft_is_number(clr[1]) || !ft_is_number(clr[2]))
		return (printf("Error\nInvalid colors\n"), free_2d(clr), 0);
	if (ft_strcmp(usb[0], "C") == 0)
	{
		data->ce[0] = ft_atoi(clr[0]);
		data->ce[1] = ft_atoi(clr[1]);
		data->ce[2] = ft_atoi(clr[2]);
		if (data->ce[0] < 0 || data->ce[1] < 0 || data->ce[2] < 0
			|| data->ce[0] > 255 || data->ce[1] > 255 || data->ce[2] > 255)
			return (printf("Error\nInvalid colors\n"), free_2d(clr), 0);
	}
	if (ft_strcmp(usb[0], "F") == 0)
	{
		data->fl[0] = ft_atoi(clr[0]);
		data->fl[1] = ft_atoi(clr[1]);
		data->fl[2] = ft_atoi(clr[2]);
		if (data->fl[0] < 0 || data->fl[1] < 0 || data->fl[2] < 0
			|| data->fl[0] > 255 || data->fl[1] > 255 || data->fl[2] > 255)
			return (printf("Error\nInvalid colors\n"), free_2d(clr), 0);
	}
	return (free_2d(clr), 1);
}

int	ft_get_map(t_data *data, int fd)
{
	char	*line;
	char	*lines;

	lines = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*lines && (!*line || ft_strcmp(line, "\n") == 0))
			return (printf("Error\nEmpty line in Map!\n"), free(line), 0);
		if (*line && ft_strcmp(line, "\n") != 0)
			lines = ft_stradd(lines, line);
		free(line);
	}
	data->map = ft_split(lines, '\n');
	free(lines);
	if (!data->map)
		return (0);
	return (1);
}

static void	ft_get_image_data(t_data *data, t_img *img, char *file)
{
	img->img = mlx_xpm_file_to_image(data->mlx,
			file, &img->width, &img->height);
	if (!img->img)
		return ;
	img->addr = (int *)mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length,
			&img->endian);
}

int	ft_get_image(t_data *data, char **usb)
{
	if (ft_strcmp(usb[0], "NO") == 0)
		ft_get_image_data(data, &data->no, usb[1]);
	else if (ft_strcmp(usb[0], "EA") == 0)
		ft_get_image_data(data, &data->ea, usb[1]);
	else if (ft_strcmp(usb[0], "WE") == 0)
		ft_get_image_data(data, &data->we, usb[1]);
	else if (ft_strcmp(usb[0], "SO") == 0)
		ft_get_image_data(data, &data->so, usb[1]);
	else if (ft_strcmp(usb[0], "C") == 0 || ft_strcmp(usb[0], "F") == 0)
	{
		if (!ft_get_colors(data, usb))
			return (0);
	}
	else
		return (printf("Error\n%s: Invalid Texture\n", usb[0]), 0);
	if ((ft_strcmp(usb[0], "NO") == 0 && !data->no.img)
		|| (ft_strcmp(usb[0], "EA") == 0 && !data->ea.img)
		|| (ft_strcmp(usb[0], "WE") == 0 && !data->we.img)
		|| (ft_strcmp(usb[0], "SO") == 0 && !data->so.img))
		return (printf("Error\n%s: Invalid path.\n", usb[1]), 0);
	return (1);
}
