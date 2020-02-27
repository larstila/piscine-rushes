# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esukava <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 10:52:21 by lkettune          #+#    #+#              #
#    Updated: 2020/02/23 22:23:15 by lkettune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2
SRC = main.c dimensions.c is_valid.c print.c split.c type.c 
OBJ = main.o dimensions.o is_valid.o print.o split.o type.o
FLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME): obj
	gcc $(FLAGS) $(OBJ) -o $(NAME)

obj: 
	gcc -c $(SRC) -I colle_2.h

clean:
	/bin/rm -f $(OBJ)

rm~:
	/bin/rm -f *~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
