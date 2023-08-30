/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mataman <mataman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:26:56 by mataman           #+#    #+#             */
/*   Updated: 2023/08/24 18:26:56 by mataman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_game.h"

int	first_and_last_row_control(t_map *map, int y)
{
	int	x;
	int	len;

	len = map->map_line;
	if (y == 0 || y == (len - 1))
	{
		x = 0;
		while (map->map[y][x] != '\n')
		{
			if (map->map[0][x] != '1')
				return (1);
			if (map->map[len - 1][x] != '1')
				return (len);
			x++;
		}
	}
	return (0);
}

int	wall_middle(t_map *map, int y)
{
	int	line_len;

	line_len = ft_strlen(map->map[0]) - 2;
	while (map->map[y] != 0)
	{
		if (map->map[y][0] != '1'
				|| map->map[y][line_len] != '1')
			return (y + 1);
		y++;
	}
	return (0);
}

int	wall_control(t_map *map)
{
	int	y;
	int	value;
	int	value2;

	y = 0;
	value = first_and_last_row_control(map, y);
	if (value != 0)
	{
		ft_err(6);
		return (1);
	}
	y = 1;
	value2 = wall_middle(map, y);
	if (value2 != 0)
	{
		ft_err(6);
		return (1);
	}
	return (0);
}
