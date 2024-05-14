CC = cc 
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread
RM = rm -f
AR = ar rc
HEADER = philo.h
NAME = philo 

SRCS = main.c ft_atoi.c ft_isdigit.c utils.c philo_life.c initialize.c start_simulation.c monitoring.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)
	@echo "philo Good"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaned"
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean