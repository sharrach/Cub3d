# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 17:38:52 by sharrach          #+#    #+#              #
#    Updated: 2023/02/04 16:37:21 by sharrach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

HEADER	=	includes/cub3d.h

SRCS	=	srcs/main.c\
			srcs/ft_read_map.c\
			srcs/ft_move_player.c\
			srcs/ft_draw_minimap.c\
			srcs/ft_render_next_frame.c\
			srcs/ft_wall_distance.c\
			srcs/ft_put_pixel.c\
			srcs/ft_draw_rays.c\
			srcs/ft_floor_ceilling.c\
			srcs/ft_draw_rect.c\
			srcs/ft_get_map.c\
			srcs/ft_utils.c\
			srcs/ft_read_map_utils.c\
			srcs/ft_free2d.c\
			srcs/ft_exit_program.c\
			srcs/ft_draw_walls.c


OBJS	=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

LIBFT	=	libft

LIB		=	$(LIBFT)/libft.a

# UNAME_S := $(shell uname -s)
# ifeq ($(UNAME_S), Darwin)
# 	MLX_DIR		=	mlx_macos
# 	MLX			=	$(MLX_DIR)/libmlx.a
# 	MLX_IFLAGS	=	-Imlx_macos
# 	MLX_LFLAGS	=	-framework OpenGL -framework AppKit
# endif
# ifeq ($(UNAME_S), Linux)
# 	MLX_DIR		=	mlx_linux
# 	MLX			=	$(MLX_DIR)/libmlx.a
# 	MLX_IFLAGS	=	-I/usr/include -Imlx_linux -O3
# 	MLX_LFLAGS	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
# endif

%.o: %.c $(HEADER)
			$(CC) $(CFLAGS) -Imlx -c $< -o $@ -fsanitize=address

$(NAME):	$(OBJS) $(HEADER)
			make -C libft
			$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit $(LIB) -o $(NAME) -fsanitize=address

# %.o: %.c $(HEADER)
# 			$(CC) $(CFLAGS) $(MLX_IFLAGS) -c $< -o $@

# $(NAME)	:	$(LIB) $(MLX) $(OBJS) $(HEADER)
# 			$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) $(MLX_LFLAGS) -o $(NAME)

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