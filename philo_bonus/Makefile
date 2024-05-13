CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc
HEADER = philo_bonus.h
NAME = philo_bonus

SRCS = main_bonus.c ft_atoi_bonus.c ft_isdigit_bonus.c utils_bonus.c philo_life_bonus.c  \
	   monitor_bonus.c simulation_bonus.c init_bonus.c
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