NAME=a.out

# Compilador y flags
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
DEBUGFLAGS=-fsanitize=address -g

# Archivos fuente y objetos
SRCS=main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS=$(SRCS:.cpp=.o)

# Regla por defecto
all: $(NAME)

# Regla para construir el ejecutable
$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Regla para compilar archivos objeto
%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para debug (compila con fsanitize=address y -g)
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: fclean $(NAME)

# Limpiar archivos objeto
clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS)

# Limpiar todo (archivos objeto y ejecutable)
fclean: clean
	@echo "Cleaning executable..."
	rm -f $(NAME)

# Reconstruir todo
re: fclean all