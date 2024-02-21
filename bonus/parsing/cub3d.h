/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-zeh <mben-zeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:52:00 by mben-zeh          #+#    #+#             */
/*   Updated: 2023/11/14 21:58:20 by mben-zeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./../libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_textur
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			floor;
	int			ceil;
}				t_textur;

typedef struct s_player
{
	int			pos;
	int			dir;
	int			x;
	int			y;

}				t_player;

typedef struct s_mape
{
	char		**map;
	t_player	player;
	int			width;
	int			height;
}				t_mape;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_mape		map;
	t_textur	textur;
}				t_data;

void			msg_error(int i);
int				ft_check_space(char *str);
int				ft_initializ_color(t_data *data, char **tab);
int				ft_initializ_fd(t_data *data, char **tab);
void			check_line(t_data *data, char *str, char **temp, int *check);
int				check_and_open(char *filename, char *format);
int				ft_strcmp(const char *s1, const char *s2);
void			check_and_lead(int fd, t_data *data);
int				ft_atoi_check(char *str);
void			ft_check_and_lead(int fd, t_data *data);
void			ft_free(char **arg);
int				ft_check_map(char **tab, t_data *data);
int				ft_check_line(char **tab, t_data *data, int *check);
int				ft_check_line_map(t_data *data, char *str);
int				check_color(char *str);
t_data			parsing(int ac, char **av);
char			**ft_spl(char *str);

#endif