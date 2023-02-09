# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: steh <steh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 08:54:37 by steh              #+#    #+#              #
#    Updated: 2022/06/19 09:10:28 by steh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# implicit variables or nonchanging variables
CC				:= gcc
CFLAGS			:= -Wall -Werror -Wextra
SRC				:= $(wildcard *.c)
OBJ				:= $(patsubst %.c, %.o, $(SRC))
.PHONY			: all clean fclean re

NAME			:= test

all				: $(NAME)
					@./$(NAME)

$(NAME)			: $(OBJ)
					@$(CC) $(CFLAGS) $(OBJ) -o $@
					@echo "compiled"

# $(OBJ)			: $(SRC)
# 					$(CC) -c $< -o $@

clean			:
					@$(RM) $(OBJ)
					@echo "removed obj files"

fclean			: clean
					@$(RM) $(NAME)
					@echo "removed obj files and program"

re				: fclean all