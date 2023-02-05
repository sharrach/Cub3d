# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 17:38:52 by sharrach          #+#    #+#              #
#    Updated: 2023/02/05 22:49:23 by sharrach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

HEADER	=	includes/cub3d.h

SRCS	=	srcs/main.c\
			srcs/ft_read_map.c\
			srcs/ft_move_player.c\
			srcs/ft_render_next_frame.c\
			srcs/ft_wall_distance.c\
			srcs/ft_put_pixel.c\
			srcs/ft_floor_ceilling.c\
			srcs/ft_draw_rect.c\
			srcs/ft_get_map.c\
			srcs/ft_utils.c\
			srcs/ft_read_map_utils.c\
			srcs/ft_free2d.c\
			srcs/ft_exit_program.c\
			srcs/ft_draw_walls.c

OBJS	=	$(SRCS:.c=.o)

BONUS_NAME = cub3d_bonus

BONUS_HEADER = includes/cub3d_bonus.h

SRCS_BN = 	srcs_bn/main.c\
			srcs_bn/ft_read_map.c\
			srcs_bn/ft_move_player.c\
			srcs_bn/ft_draw_minimap.c\
			srcs_bn/ft_render_next_frame.c\
			srcs_bn/ft_wall_distance.c\
			srcs_bn/ft_put_pixel.c\
			srcs_bn/ft_floor_ceilling.c\
			srcs_bn/ft_draw_rect.c\
			srcs_bn/ft_get_map.c\
			srcs_bn/ft_utils.c\
			srcs_bn/ft_read_map_utils.c\
			srcs_bn/ft_free2d.c\
			srcs_bn/ft_exit_program.c\
			srcs_bn/ft_mouse_movement.c\
			srcs_bn/ft_draw_walls.c

OBJS_BN	=	$(SRCS_BN:.c=.o)

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

%.o: %.c $(HEADER) $(BONUS_HEADER)
			$(CC) $(CFLAGS) $(MLX_IFLAGS) -c $< -o $@

$(NAME)	:	$(LIB) $(MLX) $(OBJS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) $(MLX_LFLAGS) -o $(NAME)

$(BONUS_NAME)	:	$(LIB) $(MLX) $(OBJS_BN) $(BONUS_HEADER)
			$(CC) $(CFLAGS) $(OBJS_BN) $(LIB) $(MLX) $(MLX_LFLAGS) -o $(BONUS_NAME)

$(LIB):
			make -C $(LIBFT)

all		:	$(NAME)

bonus	:	$(BONUS_NAME)

clean	:
			$(RM) $(OBJS)
			$(RM) $(OBJS_BN)
			make clean -C $(LIBFT)

fclean	:	clean
			$(RM) $(NAME)
			$(RM) $(BONUS_NAME)
			make fclean -C $(LIBFT)

re		:	fclean all

.PHONY	:	all clean fclean re