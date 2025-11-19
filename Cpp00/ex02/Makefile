NAME=Account

# Compiler and flags
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
DEBUGFLAGS=-fsanitize=address -g

# Source files and object files
SRCS=Account.cpp tests.cpp
OBJS=$(SRCS:.cpp=.o)

# Default rule
all: $(NAME)

# Rule to build the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Rule to compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Debug rule (compiles with fsanitize=address and -g)
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: fclean $(NAME)

# Clean object files
clean:
	rm -f $(OBJS)

# Full cleanup (object files and executable)
fclean: clean
	rm -f $(NAME)

# Full rebuild
re: fclean all

# Declare these rules as not files
.PHONY: all clean fclean re