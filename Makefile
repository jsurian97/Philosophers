# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsurian <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 12:55:27 by jsurian           #+#    #+#              #
#    Updated: 2025/05/08 14:19:02 by jsurian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom des executables
NAME = philo

# Repertoires
SRC_DIR = src

# Fichiers sources
SRC = $(SRC_DIR)/0_main.c	\
	  $(SRC_DIR)/1_initing_entry.c	\
	  $(SRC_DIR)/2_initing_philos.c	\
	  $(SRC_DIR)/3.0_starting.c	\
	  $(SRC_DIR)/3.1_starting.c	\
	  $(SRC_DIR)/4_finishing.c	\
	  $(SRC_DIR)/utils.c	\

OBJDIR = build

# Fichiers objets
OBJ = $(SRC:.c=.o)

# Option de compilation
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror 
RM = rm -f

# Commandes Makefile

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -g -Wall -Wextra -Werror -Iincludes -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
