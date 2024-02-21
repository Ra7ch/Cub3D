/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:15:24 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/14 22:45:08 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "../includes/game.h"
# define FOV_DEGREES M_PI
# define NUM_RAYS WINDOW_WEIGHT

t_pos	*raycastx_2(t_game *game, t_pos collision, double xstep, double ystep);
t_pos	*raycasty_2(t_game *game, t_pos collision, double xstep, double ystep);
t_pos	*raycastx(t_pos *player, t_game *game, double rayangle);
t_pos	*raycasty(t_pos *player, t_game *game, double rayangle);
double	distance(t_pos *point1, t_pos *point2);

#endif