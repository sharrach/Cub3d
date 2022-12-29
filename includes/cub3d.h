/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:35:01 by sharrach          #+#    #+#             */
/*   Updated: 2022/12/28 17:59:51 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <errno.h>

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
	int		fl[3];
	int		ce[3];
	char	**map;
	void	*mlx;
}	t_data;

int	ft_read_map(t_data *data, char *file);

#endif