/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:22:24 by sharrach          #+#    #+#             */
/*   Updated: 2023/01/30 13:30:05 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_data(t_data *data)
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

int	ft_is_init(t_data *data)
{
	if (data->ce[0] != -1 && data->ce[1] != -1
		&& data->ce[2] != -1 && data->fl[0] != -1
		&& data->fl[1] != -1 && data->fl[2] != -1
		&& data->we.img != NULL && data->ea.img != NULL
		&& data->no.img != NULL && data->so.img != NULL)
		return (0);
	return (1);
}

static int	ft_check_player_space(char **map, int x, int y)
{
	if (map[y][x] == ' '
		&& ((map[y][x + 1]
				&& ft_strchr("0NSEW", map[y][x + 1]))
			|| (x >= 1 && ft_strchr("0NSEW", map[y][x - 1]))
			|| (map[y + 1] && x < (int)ft_strlen(map[y + 1])
				&& ft_strchr("0NSEW", map[y + 1][x]))
			|| (y >= 1 && x < (int)ft_strlen(map[y - 1])
				&& ft_strchr("0NSEW", map[y - 1][x]))))
		return (printf("Error\nMap not closed.\n"), 0);
	else if (ft_strchr("0NSEW", map[y][x])
		&& ((!map[y][x + 1] || (map[y][x + 1]
					&& map[y][x + 1] == ' '))
			|| (x < 1 || (x >= 1 && map[y][x - 1] == ' '))
			|| (!map[y + 1]
				|| (map[y + 1]
					&& x >= (int)ft_strlen(map[y + 1]))
				|| (map[y + 1]
					&& x < (int)ft_strlen(map[y + 1])
					&& map[y + 1][x] == ' '))
			|| (y < 1
				|| (y >= 1 && x >= (int)ft_strlen(map[y - 1]))
				|| (y >= 1 && x < (int)ft_strlen(map[y - 1])
					&& map[y - 1][x] == ' '))))
		return (printf("Error\nMap not closed.\n"), 0);
	return (1);
}

int	ft_map_closed(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (!ft_check_player_space(data->map, x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
