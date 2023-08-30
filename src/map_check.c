/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mataman <mataman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:35:17 by mataman           #+#    #+#             */
/*   Updated: 2023/08/28 20:18:47 by mataman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_game.h" 

int	filecontrol(int argc, char *argv)
{
	if (argc != 2)
		ft_err(-1);
	if (argv[ft_strlen(argv) - 1] != 'r' && argv[ft_strlen(argv) - 2] != 'e' && \
		argv[ft_strlen(argv) - 3] != 'b' && argv[ft_strlen(argv) - 4] != '.')
		ft_err(0);
	return (0);
}

int	map_control(t_map *map)
{
	if (rectangle(map) || char_control(map) || wall_control(map) || \
			invalid_char_control(map) || gamer_control(map))
	{
		free_map(map);
		return (1);
	}
	free_map(map);
	return (0);
}

int	map_read_control(t_map *map, char *file_name)
{
	read_and_save_map(map, file_name);
	if (!(map->map))
	{
		ft_err(1);
		return (1);
	}
	return (0);
}

int	rectangle(t_map *map)
{
	int	y;
	int	x;
	int	len;

	len = ft_strlen(map->map[0]);
	y = 0;
	while (y < map->map_line)
	{
		x = 0;
		while (map->map[y] && map->map[y][x] != '\n' && \
			x < (int)(ft_strlen(map->map[y])))
			x++;
		if (x != len -1)
		{
			ft_err(2);
			return (1);
		}
		y++;
	}
	return (0);
}
