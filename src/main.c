/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mataman <mataman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:18:29 by mataman           #+#    #+#             */
/*   Updated: 2023/08/24 18:18:29 by mataman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_game.h"

int	map_init(t_map *map, char *argc)
{
	int	x;

	map_read_control(map, argc);
	map->p_move_c = 0;
	map->mlx = mlx_init();
	x = ft_strlen(map->map[0]) - 1;
	map->mlx_win = mlx_new_window(map->mlx, \
		64 * x, 64 * map->map_line, "SO_LONG_GAME");
	if (!map->mlx || !map->mlx_win || create_xpm(map))
	{
		ft_err(5);
		return (1);
	}
	win_put_img(map);
	mlx_string_put(map->mlx, map->mlx_win, 15, 15, 16777215, "0");
	mlx_hook(map->mlx_win, 2, 0, ft_move, map);
	mlx_hook(map->mlx_win, 17, 0, ft_exit, map);
	mlx_loop(map->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (filecontrol(argc, argv[1]) || map_read_control(&map, argv[1]))
		return (1);
	if (map_control(&map))
		return (1);
	if (map_init(&map, argv[1]))
		return (1);
	return (0);
}
