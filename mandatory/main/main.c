/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:23:31 by raitmous          #+#    #+#             */
/*   Updated: 2023/11/17 23:47:14 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	map_hidth(char **array)
{
	int	hidth;

	hidth = 0;
	while (array[hidth] != NULL)
		hidth++;
	return (hidth);
}

int	*ft_len(t_game *game)
{
	int	*len;
	int	i;

	i = 0;
	len = malloc(sizeof(int) * game->height);
	if (!len)
		(printf("Error\n"), exit(1));
	while (game->map[i])
	{
		len[i] = ft_strlen(game->map[i]);
		i++;
	}
	return (len);
}

void	game_initialise(t_game *game, int ac, char **av)
{
	game->data = parsing(ac, av);
	game->wall = malloc(sizeof(t_wall) * WINDOW_WEIGHT);
	game->map = game->data.map.map;
	game->texture = game->data.textur;
	game->height = map_hidth(game->map);
	game->len = ft_len(game);
	game->player = find_player(game->map, game);
	game->xtile = 64;
	game->ytile = 64;
	game->player_size = (((game->xtile + game->ytile) / 2) / 5);
	game->pixel_player = malloc(sizeof(t_pos));
	game->pixel_player->x = game->player->x * (double)game->xtile;
	game->pixel_player->y = game->player->y * game->ytile;
	game->move_up = 0;
	game->move_down = 0;
	game->move_left = 0;
	game->move_right = 0;
	game->intro_lock = 0;
}

int	ft_exit(t_game *game)
{
	int	i;

	i = 0;
	free(game->wall);
	free(game->pixel_player);
	free(game->player);
	while (game->map[i])
		free(game->map[i++]);
	free(game->len);
	ft_free_images(game);
	free(game->map);
	free(game->texture.ea);
	free(game->texture.we);
	free(game->texture.so);
	free(game->texture.no);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game_initialise(&game, argc, argv);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WINDOW_WEIGHT, WINDOW_HEIGHT, "Cub3D");
	game.image = create_image(game.mlx, WINDOW_WEIGHT, WINDOW_HEIGHT);
	initialise_images(&game);
	game.intro_lock = 1;
	game.i = 0;
	mlx_hook(game.win, 2, 1L << 0, onkeypress, &game);
	mlx_hook(game.win, 3, 1L << 1, onkeyrelease, &game);
	mlx_loop_hook(game.mlx, drawall, &game);
	mlx_hook(game.win, 17, 0, ft_exit, (void *)&game);
	mlx_loop(game.mlx);
}
