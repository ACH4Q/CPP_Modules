NAME = fixed

SRC = main.cpp Fixed.cpp Point.cpp

FLAGS = -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean :
	rm -rf $(NAME)

re: clean all

.PHONY: all clean re fclean