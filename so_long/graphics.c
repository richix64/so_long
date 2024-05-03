/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <rpocater@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:40:49 by rpocater          #+#    #+#             */
/*   Updated: 2024/02/13 18:10:11 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, width * 40, height * 40);
	game->collectables++;
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/item.xpm", &i, &j);
}

void	adding_in_graphics(t_complete *game)
{
	int	h;
	int	w;

	game->collectables = 0;
	h = 0;
	while (h < game->heightmap)
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == '1')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->barrier, w * 40, h * 40);
			if (game->map[h][w] == 'C' || game->map[h][w] == 'P')
				extra_graphics(game, h, w);
			if (game->map[h][w] == 'E')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->exit, w * 40, h * 40);
			if (game->map[h][w] == '0')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->floor, w * 40, h * 40);
			w++;
		}
		h++;
	}
}

void	extra_graphics(t_complete *game, int height, int width)
{
	if (game->map[height][width] == 'C')
		place_collectable(game, height, width);
	if (game->map[height][width] == 'P')
		place_player(game, height, width);
}
