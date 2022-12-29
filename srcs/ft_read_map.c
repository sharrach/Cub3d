/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:34:11 by sharrach          #+#    #+#             */
/*   Updated: 2022/12/29 11:05:33 by sharrach         ###   ########.fr       */
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

static int	ft_get_colors(t_data *data, char **usb)
{
	char	**clr;

	clr = ft_split(usb[1], ',');
	// printf("arrlen: %ld\n", ft_arrlen(clr));
	// printf("%s - %s - %s\n", clr[0], clr[1], clr[2]);
	if (!clr || ft_arrlen(clr) != 3 || !ft_is_number(clr[0]) 
		|| !ft_is_number(clr[1]) || !ft_is_number(clr[2]))
		return (printf("Error\nInvalid colors1\n"), free_2d(clr), 0);
	if (ft_strcmp(usb[0], "C") == 0)
	{
		data->ce[0] = ft_atoi(clr[0]);
		data->ce[1] = ft_atoi(clr[1]);
		data->ce[2] = ft_atoi(clr[2]);
		if (data->ce[0] < 0 || data->ce[1] < 0 || data->ce[2] < 0
			|| data->ce[0] > 255 || data->ce[1] > 255 || data->ce[2] > 255)
			return (printf("Error\nInvalid colors2\n"), free_2d(clr), 0);
	}
	else if (ft_strcmp(usb[0] ,"F") == 0)
	{
		data->fl[0] = ft_atoi(clr[0]);
		data->fl[1] = ft_atoi(clr[1]);
		data->fl[2] = ft_atoi(clr[2]);
		if (data->fl[0] < 0 || data->fl[1] < 0 || data->fl[2] < 0
			|| data->fl[0] > 255 || data->fl[1] > 255 || data->fl[2] > 255)
			return (printf("Error\nInvalid colors3\n"), free_2d(clr), 0);
	}
	return (free_2d(clr), 1);
}

int	ft_read_map(t_data *data, char *file)
{
	int		fd;
	char	**usb;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (printf("Error\n%s: no such file or directory.\n", file), 0);
	while(1)
	{
		file = get_next_line(fd);
		if (!file)
			break ;
		file = ft_strtrim(file, "\n");
		if (file)
			continue;
		// printf("file is : %s---\n", file);
		usb = ft_split(file, ' ');
		if(ft_strcmp(usb[0] ,"NO") == 0)
			data->no.img = mlx_xpm_file_to_image(data->mlx,
				usb[1], &data->no.width, &data->no.height);
		else if(ft_strcmp(usb[0] ,"EA") == 0)
			data->so.img = mlx_xpm_file_to_image(data->mlx,
			usb[1], &data->ea.width, &data->ea.height);
		else if(ft_strcmp(usb[0] ,"WE") == 0)
			data->ea.img = mlx_xpm_file_to_image(data->mlx,
			usb[1], &data->we.width, &data->we.height);
		else if(ft_strcmp(usb[0] ,"SO") == 0)
			data->we.img = mlx_xpm_file_to_image(data->mlx,
			usb[1], &data->so.width, &data->so.height);
		else if(ft_strcmp(usb[0] ,"C") == 0 || ft_strcmp(usb[0] ,"F") == 0)
			if (!ft_get_colors(data, usb))
				return (0);
		free_2d(usb);
	}
	close(fd);
	return (1);
}
