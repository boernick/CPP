NAME= PmergeMe
SRC= PmergeMe.cpp main.cpp
OBJ= $(SRC:.cpp=.o)
CPP= c++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJ)
		@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME) 
		@echo "PmergeMe compiled successfully ✅"
		
%.o: %.cpp
		@$(CPP) $(CPPFLAGS) -c $<

all: $(NAME)

clean:
		@rm -rf $(OBJ)
		@echo "Cleaned PmergeMe object files"
fclean:
		@rm -rf $(OBJ)
		@rm -rf $(NAME)
		@echo "Cleaned PmergeMe object files and PmergeMe"

re: fclean all