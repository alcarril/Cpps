NAME=a.out

CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
DEBUGFLAGS=-fsanitize=address -g

SRCS=main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

debug: CXXFLAGS += $(DEBUGFLAGS)
debug: fclean $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all