/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:46:57 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/17 23:26:51 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	iswally(t_game *game, double playerY, double playerX, double my)
{
	double	angle;
	double	increment;
	double	pointx;
	double	pointy;

	increment = M_PI / 100;
	angle = 0;
	if (my < 0)
		increment *= -1;
	while (fabs(angle) <= M_PI)
	{
		pointx = playerX + (game->player_size / 2) * cos(angle);
		pointy = playerY + (game->player_size / 2) * sin(angle);
		if ((int)(pointy / game->ytile) < 0 || (int)(pointy
				/ game->ytile) > game->height || (int)(pointx / game->xtile) < 0
			|| (int)(pointx / game->xtile) > game->len[(int)(pointy
					/ game->ytile)])
			return (1);
		if (game->map[(int)(pointy / game->ytile)][(int)(pointx
				/ game->xtile)] == '1' || game->map[(int)(pointy
				/ game->ytile)][(int)(pointx / game->xtile)] == CLOSED_DOOR)
			return (1);
		angle += increment;
	}
	return (0);
}

int	iswallx(t_game *game, double playerY, double playerX, double mx)
{
	double	angle;
	double	increment;
	double	pointx;
	double	pointy;

	increment = M_PI / 100;
	angle = M_PI / 2;
	if (mx >= 0)
		increment *= -1;
	while (angle >= -M_PI / 2 && angle <= 3 * M_PI / 2)
	{
		pointx = playerX + (game->player_size / 2) * cos(angle);
		pointy = playerY + (game->player_size / 2) * sin(angle);
		if ((int)(pointy / game->ytile) < 0 || (int)(pointy
				/ game->ytile) > game->height || (int)(pointx / game->xtile) < 0
			|| (int)(pointx / game->xtile) > game->len[(int)(pointy
					/ game->ytile)])
			return (1);
		if (game->map[(int)(pointy / game->ytile)][(int)(pointx
				/ game->xtile)] == '1' || game->map[(int)(pointy
				/ game->ytile)][(int)(pointx / game->xtile)] == CLOSED_DOOR)
			return (1);
		angle += increment;
	}
	return (0);
}

void	ft_move(t_game *game, double move_speed, double *mx, double *my)
{
	double	dir;

	dir = game->direction;
	if (game->move_up)
		dir += 0;
	else if (game->move_down)
		dir += M_PI;
	else if (game->move_left)
		dir += M_PI / 2;
	else if (game->move_right)
		dir -= M_PI / 2;
	else
		return ;
	game->player->y -= sin(dir) * move_speed;
	game->player->x += cos(dir) * move_speed;
	if (sin(dir) > 0)
		*my = -game->player_size;
	if (cos(dir) < 0)
		*mx = -game->player_size;
}

int	ft_controls(t_game *game)
{
	t_pos	tmp;
	double	move_speed;
	double	mx;
	double	my;

	move_speed = 0.05;
	tmp.x = game->player->x;
	tmp.y = game->player->y;
	mx = game->player_size;
	my = game->player_size;
	ft_move(game, move_speed, &mx, &my);
	game->pixel_player->x = game->player->x * game->xtile;
	game->pixel_player->y = game->player->y * game->ytile;
	if (iswally(game, game->pixel_player->y, tmp.x * game->xtile, my))
		game->player->y = tmp.y;
	if (iswallx(game, tmp.y * game->ytile, game->pixel_player->x, mx))
		game->player->x = tmp.x;
	game->intro_lock = 1;
	return (1);
}
