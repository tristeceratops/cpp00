NAME := megaphone
FLAGS := -Wall -Wextra -Werror -std=c++98
FILES := megaphone.cpp
OBJ := $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -L$(LIBFT) -lft -o $@

%.o: %.c
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all