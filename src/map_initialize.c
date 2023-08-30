/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mataman <mataman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:02:12 by mataman           #+#    #+#             */
/*   Updated: 2023/08/24 18:02:12 by mataman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_game.h"

int	create_xpm(t_map *map)
{
	int	x;
	int	y;

	map->img_exit = mlx_xpm_file_to_image(map->mlx, "./img/exit.xpm", &x, &y);
	map->img_coins = mlx_xpm_file_to_image(map->mlx, "./img/coins.xpm", &x, &y);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, "./img/wall.xpm", &x, &y);
	map->img_gamer = mlx_xpm_file_to_image(map->mlx, "./img/gamer.xpm", &x, &y);
	map->img_floor = mlx_xpm_file_to_image(map->mlx, "./img/floor.xpm", &x, &y);
	if (!map->img_floor || !map->img_coins || \
		!map->img_exit || !map->img_gamer || !map->img_wall)
		return (1);
	return (0);
}

void	ft_put(t_map *map, void *img, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, 64 * x, 64 * y);
}

int	win_put_img(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[y][x])
	{
		if (map->map[y] && map->map[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		if (map->map[y][x] == 'E')
			ft_put(map, map->img_exit, x, y);
		if (map->map[y][x] == 'C')
			ft_put(map, map->img_coins, x, y);
		if (map->map[y][x] == 'P')
			ft_put(map, map->img_gamer, map->p_x_location, map->p_y_location);
		if (map->map[y][x] == '0')
			ft_put(map, map->img_floor, x, y);
		if (map->map[y][x] == '1')
			ft_put(map, map->img_wall, x, y);
		x++;
	}
	return (0);
}

void	map_move(t_map *map, int x, int y)
{
	if (map->map[y][x] != '1' && map->map[y][x] != 'E')
	{
		ft_printf("Number of Movement : %d\n", ++map->p_move_c);
		if (map->map[y][x] == 'C')
			map->c_count--;
		map->map[map->p_y_location][map->p_x_location] = '0';
		map->map[y][x] = 'P';
		map->p_y_location = y;
		map->p_x_location = x;
	}
	else if (map->map[y][x] == 'E' && map->c_count == 0)
	{
		ft_printf("Number of Movement : %d\n", ++map->p_move_c);
		exit(1);
	}
}

int	ft_move(int key, t_map *map)
{
	int		x;
	int		y;
	char	*move;

	x = map->p_x_location;
	y = map->p_y_location;
	if (key == 13)
		y--;
	else if (key == 1)
		y++;
	else if (key == 2)
		x++;
	else if (key == 0)
		x--;
	else if (key == 53)
		exit(1);
	else
		return (0);
	mlx_clear_window(map->mlx, map->mlx_win);
	map_move(map, x, y);
	win_put_img(map);
	move = ft_itoa(map->p_move_c);
	mlx_string_put(map->mlx, map->mlx_win, 15, 15, 16777215, move);
	free(move);
	return (0);
}
