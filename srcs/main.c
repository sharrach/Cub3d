/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:43:30 by iellyass          #+#    #+#             */
/*   Updated: 2022/12/28 18:24:37 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char *av[])
{
    t_data data;

    if (ac != 2)
        return (printf("Error\nInvalid argument\n"), EXIT_FAILURE);
    if (!ft_read_map(&data, av[1]))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
