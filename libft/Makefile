# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 23:41:55 by raitmous          #+#    #+#              #
#    Updated: 2023/11/13 16:17:18 by raitmous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_isprint.c ft_strrchr.c ft_putchar.c ft_striteri.c ft_strnstr.c \
       ft_bzero.c ft_itoa.c ft_putendl.c ft_strjoin.c ft_strtrim.c ft_calloc.c \
       ft_memchr.c ft_putnbr.c ft_strlcat.c ft_substr.c ft_isalnum.c ft_memcmp.c \
       ft_putstr.c ft_strlcpy.c ft_tolower.c ft_isalpha.c ft_memcpy.c ft_split.c \
       ft_strlen.c ft_toupper.c ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c \
       ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c ft_putstr_fd.c 

# Bonus source files
BONUS_SRCS = ft_lstnew.c ft_lstadd_back.c ft_lstlast.c

# Object files directory
OBJS_DIR = obj

# Object files
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJS_DIR)/,$(BONUS_SRCS:.c=.o))

# Compilation flags
CFLAGS = -Wall -Wextra -Werror

# Compilation tools
CC = cc
AR = ar rc
RANLIB = ranlib
RM = rm -rf

# Output library name
NAME = libft.a

# Phony targets
.PHONY: all bonus clean fclean re

# Default target
all: ${NAME}

# Rule to create the library
${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}
	@${RANLIB} ${NAME}

# Rule to build bonus targets
bonus: ${OBJS_BONUS} all
	@${AR} ${NAME} ${OBJS_BONUS}
	@${RANLIB} ${NAME}

# Rule to compile source files
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "✨ Compiled $<"

# Rule to clean object files
clean:
	@${RM} ${OBJS_DIR}

# Rule to clean all generated files
fclean: clean
	@${RM} ${NAME}

# Rule to clean and recompile
re: fclean all

