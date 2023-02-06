/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:34:11 by sharrach          #+#    #+#             */
/*   Updated: 2023/02/06 11:43:50 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	ft_get_texts(t_data *data, int fd)
{
	char	*line;
	char	**usb;

	while (ft_is_init(data))
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!*line || ft_strcmp(line, "\n") == 0)
		{
			free(line);
			continue ;
		}
		line = ft_remove_nl(line, "\n");
		if (!line)
			break ;
		usb = ft_split(line, ' ');
		free(line);
		if (!usb)
			break ;
		if (!ft_get_image(data, usb))
			return (0);
		free_2d(usb);
	}
	return (1);
}

static void	ft_get_position(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map[++y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (ft_strchr("NSEW", data->map[y][x]))
			{
				data->player.pos.x = x + 0.5;
				data->player.pos.y = y + 0.5;
				if (data->map[y][x] == 'N')
					data->player.sight = 3 * PI_2;
				else if (data->map[y][x] == 'S')
					data->player.sight = PI_2;
				else if (data->map[y][x] == 'E')
					data->player.sight = 0;
				else if (data->map[y][x] == 'W')
					data->player.sight = PI;
			}
			x++;
		}
	}
}

static int	ft_component_check(char **map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSEW", map[y][x]))
				count ++;
			if (!ft_strchr("01NSEW ", map[y][x]))
				return (printf("Error\nInvalid Map.\n"), 0);
			x ++;
		}
		y ++;
	}
	if (count != 1)
		return (printf("Error\nInvalid player count.\n"), 0);
	return (1);
}

int	ft_read_map(t_data *data, char *file)
{
	int		fd;

	ft_init_data(data);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (printf("Error\n%s: no such file or directory.\n", file), 0);
	if (!ft_get_texts(data, fd))
		return (0);
	if (!ft_get_map(data, fd))
		return (0);
	close(fd);
	if (!ft_component_check(data->map))
		return (0);
	if (!ft_map_closed(data))
		return (0);
	ft_get_position(data);
	return (1);
}
