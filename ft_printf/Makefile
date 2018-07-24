# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatthys <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 17:40:49 by amatthys          #+#    #+#              #
#    Updated: 2018/07/22 10:18:13 by amatthys    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #
RELATIVE = .

SRC_PATH = src
SRC_NAME = divide.c ft_printf.c ft_printf_conv.c ft_putwchar.c \
		ft_uatoi_base.c ft_atoi_base.c ft_printf_ch.c ft_printf_dd.c \
		ft_putstr_def.c ft_putwstr_def.c parse.c ft_strchr.c minmax.c


SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ = $(SRC:.c=.o)

INCLUDES_PATH = includes

LIB = libft/libft.a

NAME = libftprintf.a

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
CPPFLAGS = -I $(INCLUDES_PATH)

.PHONY: clean fclean all re

all : $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

LIB :
		make -C libft

$(NAME) : $(OBJ) LIB
		cp libft/libft.a ./$(NAME)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -rf $(OBJ)
		make clean -C libft/

fclean: clean
		rm -rf $(NAME)
		make fclean -C libft/

re : fclean all
