# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 17:38:52 by sharrach          #+#    #+#              #
#    Updated: 2022/12/29 11:12:15 by sharrach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

HEADER	=	includes/cub3d.h

SRCS	=	srcs/main.c\
			srcs/ft_read_map.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

LIBFT	=	libft

LIB		=	$(LIBFT)/libft.a

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	MLX_DIR		=	mlx_macos
	MLX			=	$(MLX_DIR)/libmlx.a
	MLX_IFLAGS	=	-Imlx_macos
	MLX_LFLAGS	=	-framework OpenGL -framework AppKit
endif
ifeq ($(UNAME_S), Linux)
	MLX_DIR		=	mlx_linux
	MLX			=	$(MLX_DIR)/libmlx.a
	MLX_IFLAGS	=	-I/usr/include -Imlx_linux -O3
	MLX_LFLAGS	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

%.o: %.c $(HEADER)
			$(CC) $(CFLAGS) $(MLX_IFLAGS) -c $< -o $@

$(NAME)	:	$(LIB) $(MLX) $(OBJS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) $(MLX_LFLAGS) -o $(NAME)

$(LIB):
			make -C $(LIBFT)

all		:	$(NAME)

clean	:
			$(RM) $(OBJS)
			make clean -C $(LIBFT)

fclean	:	clean
			$(RM) $(NAME)
			make fclean -C $(LIBFT)

re		:	fclean all

.PHONY	:	all clean fclean re