# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/18 10:17:52 by amatthys     #+#   ##    ##    #+#        #
#    Updated: 2018/07/19 12:00:26 by amatthys    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

RELATIVE = .

SRC_PATH = src
SRC_NAME = print_error.c put_len.c main.c parse.c remove_access.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ = $(SRC:.c=.o)

INCLUDES_PATH = includes

NAME = lem-in

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
CPPFLAGS = -I $(INCLUDES_PATH)
INC_LIB = -I ft_printf/includes/ -I ft_printf/libft/includes/

.PHONY: clean fclean all re

all : $(NAME)

LIB :
		make -C ft_printf/

$(NAME) : $(OBJ) $(LIB) LIB
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L./ft_printf -lftprintf $(INC_LIB)

%.o: %.c
		$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_LIB) -o $@ -c $<

clean:
		rm -rf $(OBJ)
		make clean -C ft_printf/

fclean: clean
		rm -rf $(NAME)
		make fclean -C ft_printf/

re : fclean all
