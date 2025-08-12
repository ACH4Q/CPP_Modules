NAME = phonebook

SRC = PhoneBook.cpp Contacts.cpp main.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)
	
fclean : 
	rm -rf $(NAME)

re: clean all

.PHONY: all clean re