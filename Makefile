NAME = philo

SRC = main.c tools.c util.c

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g3

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all
