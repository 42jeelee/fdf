# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 15:41:26 by jeelee            #+#    #+#              #
#    Updated: 2023/03/30 03:52:37 by jeelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC		=	CC
CFLAGS	=	-Wall -Wextra -Werror

MLX		=	libmlx.dylib
MLX_DIR	=	./minilibx

SRC		=	main.c get_map.c read_map.c hooks.c utils.c utils2.c \
			set_size.c set_coordinate.c rotate_coordinate.c \
			set_image.c draw_image.c bresenham.c get_color.c \
			get_next_line.c get_next_line_utils.c

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) -lmlx -o $@
	@install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $(NAME)

%.o		:	%.c
	$(CC) $(CFLAGS) -c $?

$(MLX)	:
	@make -C $(MLX_DIR)

clean	:
	@make -C $(MLX_DIR) clean
	@rm -f $(OBJ)

fclean	:	clean
	@rm -f $(NAME)

re		:	| fclean all

.PHONY	:	all clean fclean re