/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mataman <mataman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:05:39 by mataman           #+#    #+#             */
/*   Updated: 2023/08/28 14:42:30 by mataman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_GAME_H
# define SO_LONG_GAME_H
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define MAP_CHARS "01PEC"

typedef struct s_map
{
	void	*img_gamer;
	void	*img_wall;
	void	*img_exit;
	void	*img_floor;
	void	*img_coins;
	char	**map;
	int		p_x_location;
	int		p_y_location;
	int		e_count;
	int		p_count;
	int		c_count;
	int		p_move_c;
	int		map_line;
	char	*file_name;
	void	*mlx;
	void	*mlx_win;
}				t_map;

int		ft_err(int i);
int		filecontrol(int argc, char *argv);
int		read_and_save_map(t_map *map, char *file_name);
void	map_read(t_map *map, char *file_name);
int		map_read_control(t_map *map, char *file_name);
int		rectangle(t_map *map);
void	map_char_control(t_map *map, int x, int y);
int		char_control(t_map *map);
int		invalid_char_control(t_map *map);
int		ft_exit(t_map *map);
void	free_map(t_map *map);
int		ft_move(int key, t_map *map);
void	map_move(t_map *map, int x, int y);
int		win_put_img(t_map *map);
void	ft_put(t_map *map, void *img, int x, int y);
int		create_xpm(t_map *map);
int		map_control(t_map *map);
int		map_init(t_map *map, char *argc);
int		wall_control(t_map *map);
int		first_and_last_row_control(t_map *map, int y);
int		wall_middle(t_map *map, int y);
void	recursive_p(t_map *map, int y, int x);
int		coins_control(t_map *map);
int		exit_control(t_map *map);
int		gamer_control(t_map *map);
int		map_control(t_map *map);

#endif