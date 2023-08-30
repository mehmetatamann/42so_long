/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mataman <mataman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 04:50:49 by mataman           #+#    #+#             */
/*   Updated: 2023/08/24 04:50:49 by mataman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_game.h"

void	map_char_control(t_map *map, int x, int y)
{
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'E')
				map->e_count++;
			if (map->map[y][x] == 'C')
				map->c_count++;
			if (map->map[y][x] == 'P')
			{
				map->p_y_location = y;
				map->p_x_location = x;
				map->p_count++;
			}
			x++;
		}
		y++;
	}
}

int	char_control(t_map *map)
{
	map_char_control(map, 0, 0);
	if (map->e_count != 1)
	{
		ft_err(4);
		return (1);
	}
	if (map->p_count != 1)
	{
		ft_err(4);
		return (1);
	}
	if (map->c_count == 0)
	{
		ft_err(4);
		return (1);
	}
	return (0);
}

int	invalid_char_control(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x] != '\n' && map->map[y][x] != '\0')
		{
			if (ft_strchr(MAP_CHARS, map->map[y][x]))
				x++;
			else
				ft_err(3);
		}
		y++;
	}
	return (0);
}
