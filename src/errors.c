/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mataman <mataman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:27:03 by mataman           #+#    #+#             */
/*   Updated: 2023/08/29 17:27:28 by mataman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_game.h"

int	ft_err(int i)
{
	if (i == -1)
		write(2, "Error at argc", 13);
	else if (i == 0)
		write(2, "Error at .ber\n", 14);
	else if (i == 1)
		write(2, "The file cannot be read.\n", 25);
	else if (i == 2)
		write(2, "Rectangle error on map.\n", 24);
	else if (i == 3)
		write(2, "Invalid Character\n", 18);
	else if (i == 4)
		write(2, "Invalid Number of P,E,C!\n", 25);
	else if (i == 5)
		write(2, "MLX Error!\n", 11);
	else if (i == 6)
		write(2, "Wall Error!\n", 11);
	else if (i == 7)
		write(2, "Player cannot progress to collectibles or exit!\n", 48);
	else
		write(2, "Exit!\n", 6);
	exit(1);
}
