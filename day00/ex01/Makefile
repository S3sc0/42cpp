NAME = phoneBook

SRC = phonebook.cpp contact.cpp accessors.cpp main.cpp

FLAGS = -Wextra -Wall -Werror


all: $(NAME)

$(NAME): $(SRC)
	clang++ $(FLAGS) $(SRC) -o $(NAME)

clean:

fclean:
	rm -rf $(NAME)

re: fclean all