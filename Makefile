# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahunt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/11 02:04:20 by ahunt             #+#    #+#              #
#    Updated: 2016/10/11 04:38:47 by ahunt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB_PATH = ./libft
LIB = $(LIB_PATH)/libft.a
LIB_LINK = -L$(LIB_PATH) -lft

INC_DIR = ./include
INCS = -I$(INC_DIR)

SRC_DIR = ./src
SRC_BASE = main.c \
		   alter_map.c \
		   list.c map.c \
		   solver.c \
		   utilities.c \
		   get_tetri.c \
		   read.c \
		   tetri_mem.c

OBJ_DIR = ./obj

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_BASE:.c=.o))

all: obj $(LIB) $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(LIB_PATH) $(INCS) -o $@ -c $<

$(LIB):
	make -C $(LIB_PATH)

$(NAME): $(OBJS)
	$(CC) $(LIB_LINK) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIB_PATH) clean	

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all
