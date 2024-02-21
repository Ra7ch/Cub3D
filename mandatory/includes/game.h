/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:51:48 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/18 00:41:27 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../libft/libft.h"
# include <mlx.h>
# include "../parsing/cub3d.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SCALING_FACTOR 1.0
# define TILE_SIZE 60
# define WINDOW_HEIGHT 1000
# define WINDOW_WEIGHT 1360
# define VERTICAL 0
# define HORIZONTAL 1
# define WLINUX 119
# define SLINUX 115
# define ALINUX 97
# define DLINUX 100
# define RIGHTLINUX 65361
# define LEFTLINUX 65363
# define FLINUX 102
# define WMAC 13
# define SMAC 1
# define AMAC 0
# define DMAC 2
# define RIGHTMAC 123
# define LEFTMAC 124
# define FMAC 3
# define WEST 0
# define EAST 1
# define NORTH 2
# define SOUTH 3
# define C_DOOR 4
# define O_DOOR 5
# define CLOSED_DOOR 'F'
# define OPENED_DOOR 'O'
# define OPEN 1
# define CLOSE 0

typedef struct s_position
{
	double		x;
	double		y;
}				t_pos;

typedef struct s_map
{
	t_pos		pos;
	char		c;
}				t_map;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			h;
	int			w;
	double		x;
	double		y;
}				t_image;

typedef struct s_images
{
	void		*intro;
	void		*start;
	void		*welcome;
}				t_imgs;

typedef struct s_wall
{
	int			height;
	int			side;
	double		distance;
	int			pixel;
	double		x;
	double		y;
	int			orientation;
	double		top;
	double		bottom;
}				t_wall;

typedef struct s_door
{
	int			x;
	int			y;
	int			door;
	bool		status;
}				t_door;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_pos		*player;
	double		direction;
	t_wall		*wall;
	bool		move_up;
	bool		move_down;
	bool		move_left;
	bool		move_right;
	bool		intro_lock;
	int			weight;
	int			height;
	int			num_rays;
	int			xtile;
	int			ytile;
	double		player_size;
	t_pos		*pixel_player;
	t_imgs		img;
	t_image		*image;
	t_image		textures[5];
	int			i;
	t_data		data;
	t_textur	texture;
	int			*len;
}				t_game;

void			movePup(char **map);
void			movePdown(char **map);
void			movePleft(char **map);
void			movePright(char **map);
int				CheckForWalls(t_pos *player, char **map, int i);
void			raycast(t_pos *player, t_game *game, double playerDirection);
void			renderMap(t_game *game);
char			**map_filler(char *file);
int				map_hidth(char **array);
int				map_width(char **string);
t_pos			*find_player(char **map, t_game *game);
int				onkeypress(int keycode, t_game *game);
void			draw_player(t_game *mlx);
void			draw_background(t_game *mlx);
void			renderMap(t_game *game);
int				onkeyrelease(int keycode, t_game *game);
int				drawall(t_game *mlx);
void			render3dscene(t_game *game);
t_image			*create_image(void *mlx_ptr, int width, int height);
void			my_mlx_pixel_put(t_image *img, int x, int y, int color);
int				get_texture_color(t_image *texture, int x, int y);
int				ft_controls(t_game *mlx);
int				mouse_motion_hook(int x, int y, void *param);
void			initialise_images(t_game *game);
int				ft_exit(t_game *game);
void			ft_free_images(t_game *game);

#endif