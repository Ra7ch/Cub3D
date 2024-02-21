/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:59:37 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/14 22:49:08 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "../includes/game.h"

# define FOV_DEGREES M_PI
# define NUM_RAYS WINDOW_WEIGHT
// get_weapon_color(t_game *game, int x, int y);
void	draw_weapon(t_game *game, int x, int y);
void	draw_background(t_game *game);
void	drawLineDDA(t_game *game, t_pos *player, int i, int color);
void	draw_rays(t_game *game);
void	draw_knife(t_game *game, int x, int y);
void	draw_knife_attack_1(t_game *game, int x, int y);

#endif