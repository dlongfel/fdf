# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 13:57:39 by richardbrac       #+#    #+#              #
#    Updated: 2020/07/03 13:57:40 by richardbrac      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = ./srcs/
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c  ft_strchr.c \
		ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c ft_strclr.c ft_striter.c \
		ft_striteri.c ft_strequ.c ft_strnequ.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strmap.c ft_strmapi.c ft_strjoin.c \
		ft_strtrim.c ft_strsub.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_itoa.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		ft_lstmap.c ft_sqrt.c ft_range.c ft_uppercase.c ft_lowercase.c ft_wordcounter.c get_next_line.c

OBJ = $(SRC:.c=.o)
OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INC = libft.h get_next_line.h
INC_DIR = ./includes/
INCS = $(addprefix $(INC_DIR), $(INC))

FLAGS = -g -Wall -Werror -Wextra -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		gcc $(FLAGS) -o $@ -c $<

clean:
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
