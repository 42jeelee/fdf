# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 15:41:26 by jeelee            #+#    #+#              #
#    Updated: 2023/03/30 04:52:32 by jeelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
BONUS		=	fdf_bonus

CC			=	CC
CFLAGS		=	-Wall -Wextra -Werror

MLX			=	libmlx.dylib
MLX_DIR		=	./minilibx

SRC			=	main.c get_map.c read_map.c hooks.c utils.c utils2.c \
				set_size.c set_coordinate.c rotate_coordinate.c \
				set_image.c draw_image.c bresenham.c get_color.c \
				get_next_line.c get_next_line_utils.c

B_SRC		=	bresenham_bonus.c draw_image_bonus.c fdf_bonus.h get_color_bonus.c get_map_bonus.c \
				get_next_line_bonus.c get_next_line_bonus.h get_next_line_utils_bonus.c \
				hooks_bonus.c main_bonus.c read_map_bonus.c rotate_coordinate_bonus.c set_coordinate_bonus.c \
				set_image_bonus.c set_size_bonus.c utils2_bonus.c utils_bonus.c

OBJ			=	$(SRC:.c=.o)
B_OBJ		=	$(SRC:.c=.o)

all			:	$(NAME)

bonus		:	$(BONUS)

$(NAME)		:	$(OBJ) $(MLX_DIR)/$(MLX)
		$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) -lmlx -o $@
		@install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $(NAME)

$(BONUS)	:	$(B_OBJ) $(MLX_DIR)/$(MLX)
		$(CC) $(CFLAGS) $(B_OBJ) -L$(MLX_DIR) -lmlx -o $@
		@install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $(BONUS)

%.o			:	%.c
		$(CC) $(CFLAGS) -c $?

$(MLX_DIR)/$(MLX)	:
		@make -C $(MLX_DIR)

clean		:
		@make -C $(MLX_DIR) clean
		@rm -f $(OBJ) $(B_OBJ)

fclean		:	clean
		@rm -f $(NAME) $(BONUS)

re			:	| fclean all

.PHONY		:	all clean fclean re