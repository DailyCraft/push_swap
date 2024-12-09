# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 10:47:34 by dvan-hum          #+#    #+#              #
#    Updated: 2024/12/09 11:53:30 by dvan-hum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#CC = gcc -Wall -Wextra -Werror -O3
CC = gcc -Wall -Wextra -Werror -g -fsanitize=address

SRC = array.c big_sort_utils.c big_sort.c executions.c little_sort.c parsing.c \
	print_filter.c print.c push_swap.c
SRC_BONUS = checker_bonus.c executions.c parsing.c
OBJ = $(patsubst %.c, obj/%.o, $(SRC))
OBJ_BONUS = $(patsubst %.c, obj/%.o, $(SRC_BONUS))
INCLUDES = ./

all: $(NAME)

makelibft:
	make -C libft

$(NAME): makelibft $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -L ./libft -lft

obj/%.o: src/%.c | ./obj
	$(CC) -c $< -o $@ -I $(INCLUDES) -I ./libft

./obj:
	mkdir obj

clean:
	rm -rf ./obj
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

bonus: makelibft $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -o checker -L ./libft -lft

NB ?= 100
ARGS ?= $(shell shuf -i 1-$(NB) -n $(NB) | xargs)
ARGS := $(ARGS)
debug: all bonus
	@echo --- Program output ---
	-@bash -c "time ./$(NAME) $(ARGS)"
	@echo -n "\033[1;33mInstruction count:\033[0m "
	-@./$(NAME) $(ARGS) | wc -l
	@echo -n "\033[1;33mCheck status:\033[0m "
	-@./$(NAME) $(ARGS) | ./checker $(ARGS)
	@echo "\033[1;33mWith args:\033[0m $(ARGS)"

py: all
	[ ! -f "pyviz.py" ] && curl -O https://raw.githubusercontent.com/AdrianWR/push_swap/refs/heads/main/pyviz.py || :
	python3 pyviz.py $(ARGS)

gdb: all
	gdb -q -tui --args $(NAME) $(ARGS)