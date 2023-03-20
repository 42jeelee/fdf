# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 17:46:30 by jeelee            #+#    #+#              #
#    Updated: 2023/03/20 19:58:52 by jeelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC		=	CC
CFLAGS	=	-Wall -Wextra -Werror

MLX		=	libmlx.dylib
MLX_DIR	=	./minilibx

SRC		=	main.c draw.c hooks.c

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