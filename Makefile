# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 10:47:34 by dvan-hum          #+#    #+#              #
#    Updated: 2024/11/18 22:52:43 by dvan-hum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -Wall -Wextra -Werror

SRC = push_swap.c executions.c sort.c
SRC_BONUS = checker_bonus.c
OBJ = $(patsubst %.c, obj/%.o, $(SRC))
OBJ_BONUS = $(patsubst %.c, obj/%.o, $(SRC_BONUS))
INCLUDES = ./

all: $(NAME)

makelibft:
	make -C libft
	cp libft/libft.a ./$(NAME)

$(NAME): makelibft $(OBJ)
	$(CC) $(OBJ) -I ./libft -L ./libft -lft -o $(NAME)

obj/%.o: %.c | ./obj
	$(CC) -c $< -o $@ -I $(INCLUDES) -I ./libft -L ./libft -lft

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
	$(CC) $(OBJ_BONUS) -I ./libft -L ./libft -lft -o checker

ARGS := $(shell shuf -i 1-1000 -n 100 | xargs)
debug: makelibft all
	@echo --- Program output ---
	@./$(NAME) $(ARGS)
	@echo -n "\033[1;33mInstruction count:\033[0m "
	@./$(NAME) $(ARGS) | wc -l
	@echo -n "\033[1;33mCheck status:\033[0m "
	@./$(NAME) $(ARGS) | ./checker $(ARGS)
	@echo "\033[1;33mWith args:\033[0m $(ARGS)"