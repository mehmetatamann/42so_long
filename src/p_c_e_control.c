/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamer_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mataman <mataman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:31:59 by mataman           #+#    #+#             */
/*   Updated: 2023/08/24 18:31:59 by mataman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_game.h"

void	recursive_p(t_map *map, int y, int x)
{
	if (map->map[y][x + 1] == '0' || map->map[y][x + 1] == 'C')
	{
		map->map[y][x + 1] = 'P';
		recursive_p(map, y, x + 1);
	}
	if (map->map[y][x - 1] == '0' || map->map[y][x - 1] == 'C')
	{
		map->map[y][x - 1] = 'P';
		recursive_p(map, y, x - 1);
	}
	if (map->map[y + 1][x] == '0' || map->map[y + 1][x] == 'C')
	{
		map->map[y + 1][x] = 'P';
		recursive_p(map, y + 1, x);
	}
	if (map->map[y - 1][x] == '0' || map->map[y - 1][x] == 'C')
	{
		map->map[y - 1][x] = 'P';
		recursive_p(map, y - 1, x);
	}
}

int	coins_control(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x] != 0 && map->map[y][x] != '\n')
		{
			if (map->map[y][x] == 'C')
			{
				ft_err(7);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	exit_control(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y] != 0)
	{
		x = 0;
		while (map->map[y][x] != '\n')
		{
			if (map->map[y][x] == 'E')
				break ;
			x++;
		}
		if (map->map[y][x] == 'E')
			break ;
		y++;
	}
	if (map->map[y][x + 1] == 'P' || map->map[y][x - 1] == 'P' ||
			map->map[y + 1][x] == 'P' || map->map[y - 1][x] == 'P')
		return (0);
	ft_err(7);
	return (1);
}

int	gamer_control(t_map *map)
{
	recursive_p(map, map->p_y_location, map->p_x_location);
	if (coins_control(map) || exit_control(map))
		return (1);
	return (0);
}
