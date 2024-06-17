NAME = philo
CC = cc
NORM = norminette
CFLAGS = -g -Wall -Wextra -Werror -pthread
RM = rm -rf
OBJS_DIR = objs/
SRCS_DIR = srcs/

//SRCS = $(addprefix $(SRCS_DIR), $(wildcard *.c))
SRCS = $(wildcard $(SRCS_DIR)*.c)
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all : $(OBJS_DIR) $(NAME)

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

re : fclean all

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

.PHONY : clean fclean re all bonus
