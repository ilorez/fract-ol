# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/19 11:40:47 by znajdaou          #+#    #+#              #
#    Updated: 2025/01/25 16:31:00 by znajdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs

BUILD_DR = ./build/
NAME = fractol

LIBFT_DR = ./libft

FLAGS = -Wall -Wextra -Werror #-g3 #-fsanitize=address
INCLUDES_DRS = -I./includes -I./libft/includes 
CC = cc
RM = rm -f

SRCS=  fractol.c

OBJS = $(addprefix $(BUILD_DR),$(SRCS:%.c=%.o))
green = \033[32m
reset = \033[0m

all: $(NAME)
	@echo "$(green)SUCCESS!!!$(reset)"

$(BUILD_DR)%.o: %.c | $(BUILD_DR)
	$(CC) $(FLAGS) $(INCLUDES_DRS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS) 
	make -C $(LIBFT_DR)
	$(CC) $(FLAGS) $(OBJS) $(INCLUDES_DRS) $(LIBFT_DR)/libft.a  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz  -o $(NAME)

$(BUILD_DR):
	mkdir -p $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DR) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
