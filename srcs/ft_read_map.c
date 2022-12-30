/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:34:11 by sharrach          #+#    #+#             */
/*   Updated: 2022/12/30 10:21:51 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i == 1 && (str[i] == '+' || str[i] == '-'))
		return (0);
	return (1);
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
	if (ft_strcmp(usb[0] ,"F") == 0)
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

int	ft_get_image(t_data *data, char **usb)
{
	if (ft_strcmp(usb[0], "NO") == 0)
		data->no.img = mlx_xpm_file_to_image(data->mlx,
			usb[1], &data->no.width, &data->no.height);
	else if (ft_strcmp(usb[0], "EA") == 0)
		data->ea.img = mlx_xpm_file_to_image(data->mlx,
			usb[1], &data->ea.width, &data->ea.height);
	else if (ft_strcmp(usb[0], "WE") == 0)
		data->we.img = mlx_xpm_file_to_image(data->mlx,
			usb[1], &data->we.width, &data->we.height);
	else if (ft_strcmp(usb[0], "SO") == 0)
		data->so.img = mlx_xpm_file_to_image(data->mlx,
			usb[1], &data->so.width, &data->so.height);
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

static int	ft_is_init(t_data *data)
{
	if (data->ce[0] != -1 && data->ce[1] != -1
		&& data->ce[2] != -1 && data->fl[0] != -1
		&& data->fl[1] != -1 && data->fl[2] != -1
		&& data->we.img != NULL && data->ea.img != NULL
		&& data->no.img != NULL && data->so.img != NULL)
		return (0);
	return (1);
}

static int ft_map_closed(t_data *data)
{
	int	x;
	int	y;
	
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == ' '
				&& ((data->map[y][x + 1] && (data->map[y][x + 1] == '0' || ft_strchr("NSEW", data->map[y][x + 1])))
					|| (x >= 1 && (data->map[y][x - 1] == '0' || ft_strchr("NSEW", data->map[y][x - 1])))
					|| (data->map[y + 1] && x < (int)ft_strlen(data->map[y + 1]) && (data->map[y + 1][x] == '0' || ft_strchr("NSEW", data->map[y + 1][x])))
					|| (y >= 1 && x < (int)ft_strlen(data->map[y - 1]) && (data->map[y - 1][x] == '0' || ft_strchr("NSEW", data->map[y - 1][x])))))
				return (printf("Error\nMap not closed.\n"), 0);
			// else if (data->map[y][x] == '0'
			// 		&& ((data->map[y][x + 1] && (data->map[y][x + 1] == ' ' || data->map[y][x + 1] == ' '))
			// 			|| (x >= 1 && data->map[y][x - 1] == ' ')
			// 			|| (data->map[y + 1] && x < (int)ft_strlen(data->map[y + 1]) && data->map[y + 1][x] == ' ')
			// 			|| (y >= 1 && x < (int)ft_strlen(data->map[y - 1]) && data->map[y - 1][x] == ' ')))
			// 		return (printf("Error\nMap not closed.\n"), 0);
			else if (ft_strchr("0NSEW", data->map[y][x])
					&& ((!data->map[y][x + 1] || (data->map[y][x + 1] && data->map[y][x + 1] == ' '))
						|| (x >= 1 && data->map[y][x - 1] == ' ')
						|| ((!data->map[y + 1] || data->map[y + 1]) && x < (int)ft_strlen(data->map[y + 1]) && data->map[y + 1][x] == ' ')
						|| (y >= 1 && x < (int)ft_strlen(data->map[y - 1]) && data->map[y - 1][x] == ' ')))
					return (printf("Error\nMap not closed.\n"), 0);

			x++;
		}
		y++;
	}
	return (1);
}

// static int ft_map_closed(t_data *map)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while(map->map[0][x] && map->map[0][x] == '1' && map->map[0][x] == ' '
// 			&& map->map[ft_arrlen(map->map) - 1][x] == '1' && map->map[ft_arrlen(map->map) - 1][x] == ' ')
// 				x++;
// 	if (!map->map[0][x])
// 		return (0);
// 	while(map->map[y] && map->map[y][0] == '1' && map->map[y][0] == ' '
// 			&& map->map[y][ft_strlen(map->map[0] -1)] == '1' && map->map[y][ft_strlen(map->map[0] -1)] == ' ')
// 				y++;
// 	if (y != ft_arrlen(map->map))
// 		return (0);
// 	y = 1;
// 	while(map->map[y])
// 	{
// 		x = 0;
// 		while(map->map[y][x])
// 		{
// 			if (map->map[y][x] == '0'
// 				&& (map->map[y][x + 1] == ' '
// 					|| map->map[y][x - 1] == ' '
// 					|| map->map[y + 1][x] == ' '
// 					|| map->map[y - 1][x] == ' ')) 
// 				return (0);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (1);
// }

int	ft_get_texts(t_data *data, int	fd)
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
			continue;
		}
		line = ft_strtrim(line, "\n");
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

static void ft_init_data(t_data *data)
{
	data->ce[0] = -1;
	data->ce[1] = -1;
	data->ce[2] = -1;
	data->fl[0] = -1;
	data->fl[1] = -1;
	data->fl[2] = -1;
	data->we.img = NULL;
	data->ea.img = NULL;
	data->no.img = NULL;
	data->so.img = NULL;
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
	if (!ft_map_closed(data))
		return (0);
	return (1);
}
