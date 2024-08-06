NAME := megaphone
FLAGS := -Wall -Wextra -Werror -std=c++98
FILES := megaphone.cpp
OBJ := $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $@

%.o: %.c
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all