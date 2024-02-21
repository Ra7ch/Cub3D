# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 21:13:21 by mben-zeh          #+#    #+#              #
#    Updated: 2023/11/18 00:40:39 by raitmous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Cub3D
NAME_B			= Cub3D_BONUS

LIBFT			= ./libft/libft.a

LIBFT_DIR = ./libft

CC				= cc

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address -g3 #-I/minilibx-linux
MINILIBX_FLAGS_LINUX	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MINILIBX_FLAGS_MAC		= -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -Ofast -O3

REMOVE			= rm -rf

SRCS_DIR		= ./mandatory/

SRCS			= $(addprefix ${SRCS_DIR}images/, textures.c) \
				$(addprefix ${SRCS_DIR}main/, main.c player.c) \
				$(addprefix ${SRCS_DIR}movement/, key.c move.c) \
				$(addprefix ${SRCS_DIR}raycast/, raycast_h.c raycast_v.c raycast.c) \
				$(addprefix ${SRCS_DIR}rendering/, 3d.c color.c draw.c) \
				$(addprefix ${SRCS_DIR}parsing/, parsing.c gnl/get_next_line.c gnl/get_next_line_utils.c libft_utils.c utils.c check.c)

SRCS_DIR_B		= ./bonus/

SRCS_B			= $(addprefix ${SRCS_DIR_B}images/, textures.c strjoin.c) \
				$(addprefix ${SRCS_DIR_B}main/, doors.c main.c player.c) \
				$(addprefix ${SRCS_DIR_B}movement/, key.c mouse.c move.c) \
				$(addprefix ${SRCS_DIR_B}raycast/, raycast_h.c raycast_v.c raycast.c) \
				$(addprefix ${SRCS_DIR_B}rendering/, 3d.c color.c draw_rays.c draw.c mini_map.c weapon.c knife.c) \
				$(addprefix ${SRCS_DIR_B}parsing/, parsing.c gnl/get_next_line.c gnl/get_next_line_utils.c libft_utils.c  utils.c  check.c)

OBJS_DIR = ./obj/

OBJS = ${SRCS:./%.c=${OBJS_DIR}/%.o}

OBJS_B = ${SRCS_B:./%.c=${OBJS_DIR}/%.o}

all:	${LIBFT} ${NAME}

bonus : ${LIBFT} ${NAME_B}
	
a: all clean

${OBJS_DIR}/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@
	@echo "✨ Compiled $<"

${NAME}:	${OBJS}
	@echo "🚀 Compiling $(NAME)..."
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MINILIBX_FLAGS_LINUX} -o ${NAME}
	@echo "✅ Compilation completed! Enjoy your game! 🎮"

${NAME_B}:	${OBJS_B}
	@echo "🚀 Compiling $(NAME_B)..."
	@${CC} ${CFLAGS} ${OBJS_B} ${LIBFT} ${MINILIBX_FLAGS_LINUX} -o ${NAME_B}
	@echo "✅ Compilation completed! Enjoy your game! 🎮"

${LIBFT}:
	@make -s bonus -C ./libft
	@echo "📚 Libft compilation completed!"

clean:
	@${REMOVE}  ${OBJS_DIR}
	@${REMOVE}  ${OBJS_DIR_B}
	@make -s clean -C ./libft
	@echo "🧹 Cleaned up object files! 🧹"
	

fclean:		clean
	@${REMOVE} ${NAME}
	@${REMOVE} ${NAME_B}
	@make -s fclean -C ./libft
	@echo "🚮 Cleaned up executable! 🚮"

re:			fclean all

re_bonus:			fclean bonus

.PHONY:		all bonus clean fclean re a