# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 10:47:34 by dvan-hum          #+#    #+#              #
#    Updated: 2024/12/16 08:07:28 by dvan-hum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -Wall -Wextra -Werror -O3

SRC = array.c big_sort_utils.c big_sort.c executions.c little_sort.c parsing.c \
	print_filter.c print.c push_swap.c
SRC_BONUS = checker_bonus.c executions.c parsing.c
OBJ = $(SRC:%.c=obj/%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=obj/%.o)
INCLUDES = ./
LIBS = libft/libft.a

ifndef VERBOSE
MAKEFLAGS += --silent
endif

all: $(NAME)

%.a:
	make -C $(shell dirname $@)

$(NAME): $(LIBS) $(OBJ)
	echo "\n\t\e[1;32mBuilding\e[0m \e[36m$(NAME)\e[0m\n"
	$(CC) $(OBJ) -o $(NAME) -L ./libft -lft

checker: $(LIBS) $(OBJ_BONUS)
	echo "\n\t\e[1;32mBuilding\e[0m \e[36mchecker\e[0m\n"
	$(CC) $(OBJ_BONUS) -o checker -L ./libft -lft

obj/%.o: src/%.c
	echo "$(NAME) \e[90m➤\e[0m \e[32mCompiling\e[0m \e[36m$<\e[0m"
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@ -I $(INCLUDES) -I ./libft

clean:
	echo "$(NAME) \e[90m➤\e[0m\t\e[1;31mCleaning object files\e[0m"
	rm -rf ./obj
	make -C libft clean

fclean:
	make -C libft fclean
	echo "$(NAME) \e[90m➤\e[0m\t\e[1;31mCleaning object files\e[0m"
	rm -rf ./obj
	echo "$(NAME) \e[90m➤\e[0m\t\e[31mCleaning $(NAME)\e[0m"
	rm -f $(NAME) checker

re: fclean all

bonus: checker

NB ?= 100
ARGS ?= $(shell shuf -i 1-$(NB) -n $(NB) | xargs)
ARGS := $(ARGS)
debug: all bonus
	echo --- Program output ---
	-bash -c "time ./$(NAME) $(ARGS)"
	echo -n "\033[1;33mInstruction count:\033[0m "
	-./$(NAME) $(ARGS) | wc -l
	echo -n "\033[1;33mCheck status:\033[0m "
	-./$(NAME) $(ARGS) | ./checker $(ARGS)
	echo "\033[1;33mWith args:\033[0m $(ARGS)"

py: all
	[ ! -f "pyviz.py" ] && curl -O https://raw.githubusercontent.com/AdrianWR/push_swap/refs/heads/main/pyviz.py || :
	echo "\033[1;33mWith args:\033[0m $(ARGS)"
	python3 pyviz.py $(ARGS)