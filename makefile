# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 17:59:47 by jfoltan           #+#    #+#              #
#    Updated: 2024/06/17 18:24:28 by jfoltan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -g -O0 -Wall -Wextra -Werror -pthread
RM = rm -rf
OBJS_DIR = objs/
SRCS_DIR = srcs/
INCLUDES_DIR = includes/

SRCS = $(wildcard $(SRCS_DIR)*.c)
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re