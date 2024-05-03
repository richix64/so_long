/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <rpocater@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:38:47 by rpocater          #+#    #+#             */
/*   Updated: 2024/02/13 17:41:28 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	right_move(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		ft_printf("\nYou Have Won, Congrats!\n");
		exit_point(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

static int	keyboard_w_s(t_complete *game, int movement)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 13)
	{
		if (game->map[--j][i] == '1')
			return (0);
		if (!(right_move(game, i, j)))
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (movement == 1)
	{
		if (game->map[++j][i] == '1')
			return (0);
		if (!(right_move(game, i, j)))
			return (0);
		game->map[j - 1][i] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	keyboard_a_d(t_complete *game, int movement)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 0)
	{
		if (game->map[j][--i] == '1')
			return (0);
		if (!(right_move(game, i, j)))
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (movement == 2)
	{
		if (game->map[j][++i] == '1')
			return (0);
		if (!(right_move(game, i, j)))
			return (0);
		game->map[j][i - 1] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Reamining: %i\n", game->collectables);
	return (1);
}

int	controls_working(int command, t_complete *game)
{
	int	works;

	if (command == 53)
		exit_point(game);
	if (command == 13)
		works = keyboard_w_s(game, command);
	if (command == 1)
		works = keyboard_w_s(game, command);
	if (command == 0)
		works = keyboard_a_d(game, command);
	if (command == 2)
		works = keyboard_a_d(game, command);
	if (works)
		adding_in_graphics(game);
	return (1);
}
