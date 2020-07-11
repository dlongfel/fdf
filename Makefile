# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 13:58:56 by richardbrac       #+#    #+#              #
#    Updated: 2020/07/03 13:58:56 by richardbrac      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR = ./srcs/
SRC =	main.c \
		read_file.c \
		draw.c \
		control.c \
		init.c \
		control_fts.c \
		rotation.c \
		mouse.c \
		print_menu.c \
		color.c \
		utils.c \
		error_utils.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(SRC:.c=.o)
OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INC = fdf.h key_control.h
INC_DIR = ./includes/
INCS = $(addprefix $(INC_DIR), $(INC))

LIB_OBJ = *.o
LIB_OBJ_DIR = ./libft/obj/
LIB_OBJS = $(addprefix $(LIB_OBJ_DIR), $(LIB_OBJ))
LIB_SRC_DIR = ./libft/srcs/
LIB_INC = libft.h get_next_line.h
LIB_INC_DIR = ./libft/includes/
LIB_INCS = $(addprefix $(LIB_INC_DIR), $(LIB_INC))
MLX_LIB_DIR = ./minilibx_macos/
MLX_LIB = ./minilibx_macos/libmlx.a

LIBRARIES = -framework OpenGL -framework AppKit

FLAGS = -g -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_INC_DIR) -I$(MLX_LIB_DIR)

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJ_DIR) $(LIB_OBJS) $(OBJS)
		@gcc $(OBJS) ./libft/libft.a $(MLX_LIB) -o $(NAME) $(LIBRARIES)

$(OBJ_DIR):
		@mkdir -p $@
		@mkdir -p $(LIB_OBJ_DIR)

$(LIB_OBJ_DIR)%.o: $(LIB_SRC_DIR)%.c $(LIB_INCS)
		@make -C libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		gcc $(FLAGS) -o $@ -c $<

$(MLX_LIB_DIR)%.a:
		@make -sC $(MLX_LIB_DIR)

clean:
		@make clean -C libft
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
