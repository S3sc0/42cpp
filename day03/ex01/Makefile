NAME = ScavTrap

SRC = ClapTrap.cpp ScavTrap.cpp main.cpp

FLAGS = -Wextra -Wall -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	clang++ $(FLAGS) $(SRC) -o $(NAME)

clean:

fclean:
	rm -rf $(NAME)

re: fclean all