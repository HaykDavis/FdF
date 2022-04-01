# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psoares <psoares@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 14:17:02 by psoares           #+#    #+#              #
#    Updated: 2021/10/27 16:28:29 by psoares          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


MY_FDF	= fdf

MY_FDF_SRCS = fdf.c \
			./src/keys.c \
			./src/draw.c \
			./src/utils.c \
			./src/ft_atoi.c \
			./src/rotates.c \
			./src/ft_split.c \
			./src/read_data.c \
			./src/add_to_draw.c \
			./gnl/get_next_line.c \
			./gnl/get_next_line_utils.c

HEADER		= fdf.h

MINILIBX = libmlx.a

OBJ = $(patsubst %.c,%.o,$(MY_FDF_SRCS))

CC = gcc

RM = rm -f

FRAME = -Lmlx -lmlx -framework OpenGL -framework AppKit -Wall -Werror -Wextra

FLAGS = -Wall -Werror -Wextra

all: $(MY_FDF)

$(MY_FDF) : $(OBJ) $(MY_FDF_SRCS) $(HEADER)
	@make -C mlx
	@cp mlx/$(MINILIBX) .
	@$(CC) $(FLAGS) $(FRAME) $(MY_FDF_SRCS) -o $(MY_FDF)
	@printf "FdF was build ✅\n"

bonus : all

clean:
		@$(RM) $(OBJ)
		@make clean -C mlx
		@printf "ALL is in trash 🗑\n"

fclean: clean
		@$(RM) $(MY_FDF) $(MINILIBX)

re: fclean all

rebonus: fclean bonus

.PHONY : all clean fclean re bonus rebonus