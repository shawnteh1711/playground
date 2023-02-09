# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: steh <steh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 18:59:48 by steh              #+#    #+#              #
#    Updated: 2022/07/03 00:30:55 by steh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= minishell
CC				:= gcc
CFLAGS			:= -Wall -Werror -Wextra
# SRC_DIR			:= src
OBJ_DIR			:= obj

ROOTSRC			=	$(wildcard *.c)
ROOTOBJ			=	$(ROOTSRC:%.c=%.o)
SUBDIR			=	$(shell ls -d */)
SUBSRC			=	$(shell find $(SUBDIR) -name '*.c')
SUBOBJ			=	$(SUBSRC:%.c=%.o)
BIN				=	main

INC				:=	-Iinc

$(NAME)		:	$(ROOTOBJ) $(SUBOBJ)
				$(CC) $(CFLAGS) $(INC) -o $(BIN) $(ROOTOBJ) $(SUBOBJ)

.c.o		:	
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				rm -f $(BIN) $(ROOTOBJ) $(SUBOBJ)