/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <rpocater@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:31:53 by rpocater          #+#    #+#             */
/*   Updated: 2024/02/13 19:19:46 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_errors(t_complete *game)
{
	if_walls(game);
	character_valid(game);
	check_rectangle(game);
}

void	check_rectangle(t_complete *game)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < game->heightmap)
	{
		count += width_of_map(game->map[i]);
		i++;
	}
	if (count != ((game->widthmap) * (game->heightmap)))
	{
		ft_printf("\n Map is not a rectangle\n");
		exit_point(game);
	}
}
