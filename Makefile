# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/18 10:17:52 by amatthys     #+#   ##    ##    #+#        #
#    Updated: 2018/07/24 11:09:58 by amatthys    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

RELATIVE = .

SRC_PATH = src
SRC_NAME = put_len.c main.c parse.c remove_access.c movement.c \
		   tubes.c get_ant.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ = $(SRC:.c=.o)

INCLUDES_PATH = includes

NAME = lem-in

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
CPPFLAGS = -I $(INCLUDES_PATH)
INC_lib = -I ft_printf/includes/ -I ft_printf/libft/includes/

.PHONY: clean fclean all re lib

all : $(NAME)

lib :
		make -C ft_printf/

$(NAME) : $(OBJ) lib
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L./ft_printf -lftprintf $(INC_lib)

%.o: %.c includes/lem_in.h
		$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_lib) -o $@ -c $<

clean:
		rm -rf $(OBJ)
		make clean -C ft_printf/

fclean: clean
		rm -rf $(NAME)
		make fclean -C ft_printf/

re : fclean all
