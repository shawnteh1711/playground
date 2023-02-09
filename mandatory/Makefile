# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: steh <steh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 18:59:48 by steh              #+#    #+#              #
#    Updated: 2022/07/09 19:02:18 by steh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= minishell
CC				:= gcc
CFLAGS			:= -Wall -Werror -Wextra -g
SRC_DIR			:= src
OBJ_DIR			:= obj

# main
SRC				:= $(wildcard $(SRC_DIR)/*.c)
SRC_OBJ			:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# lexer
LEXER_DIR		:= $(SRC_DIR)/lexer
LEXER_SRC		:= $(wildcard $(LEXER_DIR)/*.c)
LEXER_OBJ		:= $(patsubst $(LEXER_DIR)/%.c, $(OBJ_DIR)/%.o, $(LEXER_SRC))

# parser
PARSER_DIR		:= $(SRC_DIR)/parse
PARSER_SRC		:= $(wildcard $(PARSER_DIR)/*.c)
PARSER_OBJ		:= $(patsubst $(PARSER_DIR)/%.c, $(OBJ_DIR)/%.o, $(PARSER_SRC))

# executor
EXECUTOR_DIR	:= $(SRC_DIR)/execute
EXECUTOR_SRC	:= $(wildcard $(EXECUTOR_DIR)/*.c)
EXECUTOR_OBJ	:= $(patsubst $(EXECUTOR_DIR)/%.c, $(OBJ_DIR)/%.o, $(EXECUTOR_SRC))

# builtin
BUILTIN_DIR		:= $(SRC_DIR)/builtin
BUILTIN_SRC		:= $(wildcard $(BUILTIN_DIR)/*.c)
BUILTIN_OBJ		:= $(patsubst $(BUILTIN_DIR)/%.c, $(OBJ_DIR)/%.o, $(BUILTIN_SRC))

OBJ				:= $(LEXER_OBJ) $(PARSER_OBJ) $(EXECUTOR_OBJ) $(SRC_OBJ) $(BUILTIN_OBJ)
INC				:= -Iinc -Ilibft -I/usr/local/opt/readline/include
LINK			:= -lreadline -Llibft -lft -L/usr/local/opt/readline/lib


all				: $(NAME)

$(NAME)			: $(OBJ) $(LIBFT)
					@make -s -C libft
					@$(CC) $(CFLAGS) $(LIBFT) $(OBJ) $(INC) -o $@ $(LINK)
					@echo "$(_GREEN) Project Compiled $(_RESET)"

vpath %.c		: $(LEXER_DIR) $(PARSER_DIR) $(EXECUTOR_DIR) $(SRC_DIR) $(BUILTIN_DIR)

$(OBJ_DIR)/%.o	: %.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@
					@echo "$(_GREEN) Compiling $(_YEL) $< $(_RESET)"

# $(LIBFT)		:
# 					@make -C libft

norm			:
					@echo "$(_YEL) norminatte start $(_RESET)"
					norminette $(SRC_DIR)/*.c

clean			:
					@$(RM) $(OBJS)
					@$(RM) -r $(OBJ_DIR)
					@make clean -C libft
					@echo "$(_RED) removed obj files and obj directory $(_RESET)"

fclean			: clean
					@$(RM) $(NAME)
					@make fclean -C libft
					@echo "$(_RED) removed $(NAME) $(_RESET)"

re				: fclean all

.PHONY			: all clean fclean re


# colors
_RESET		= \033[0m
_BOLD		= \033[1m
_RED		= \033[0;31m
_GREEN		= \033[0;32m
_YEL		= \033[0;33m
_CYN		= \033[0;36m