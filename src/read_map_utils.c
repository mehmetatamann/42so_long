/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mataman <mataman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 04:20:06 by mataman           #+#    #+#             */
/*   Updated: 2023/08/24 04:20:06 by mataman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_game.h"

void	map_read(t_map *map, char *file_name)
{
	int		len;
	int		fd;
	char	c;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		map->map_line = 0;
		return ;
	}
	len = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			len++;
	}
	len++;
	close(fd);
	map->map = malloc(sizeof(char *) * len + 1);
	if (!map->map)
		return ;
	map->map[len + 1] = 0;
	map->map_line = len;
}

int	read_and_save_map(t_map *map, char *file_name)
{
	int	fd;
	int	i;

	map_read(map, file_name);
	if (!(map->map) || map->map_line <= 0)
	{
		map->map = 0;
		return (1);
	}
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		free(map->map);
		return (1);
	}
	i = 0;
	map->map[i] = get_next_line(fd);
	while (map->map[i])
	{
		i++;
		map->map[i] = get_next_line(fd);
	}
	close(fd);
	return (0);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_line)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

int	ft_exit(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img_floor);
	mlx_destroy_image(map->mlx, map->img_wall);
	mlx_destroy_image(map->mlx, map->img_exit);
	mlx_destroy_image(map->mlx, map->img_gamer);
	mlx_destroy_image(map->mlx, map->img_coins);
	mlx_clear_window(map->mlx, map->mlx_win);
	free_map(map);
	exit(1);
	return (0);
}
