
NAME=Weapon

CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
DEBUGFLAGS=-fsanitize=address -g

SRCS=main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@


debug: CXXFLAGS += $(DEBUGFLAGS)
debug: fclean $(NAME)

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS)


fclean: clean
	@echo "Cleaning executable..."
	rm -f $(NAME)


re: fclean all