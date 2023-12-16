# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 10:54:58 by jfoltan           #+#    #+#              #
#    Updated: 2023/12/16 12:40:58 by jfoltan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS_DIR = ./src/



CFLAGS =  -Wall -Wextra -Werror -pthread -g

SRCS =  $(SRCS_DIR)main.c $(SRCS_DIR)utils.c $(SRCS_DIR)philos.c $(SRCS_DIR)utils_ft.c

all: $(NAME)


$(NAME): $(SRCS_DIR) $(SRCS) 
	cc $(CFLAGS) $(INCLUDES) $(SRCS) -o $(NAME)
	
clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re