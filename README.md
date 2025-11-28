# C++ Modules

This repository contains solutions for the 42 school C++ modules (Cpp00 - Cpp03).

## Modules

### Cpp00
Introduction to C++ basics: namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff.

- **ex00**: Megaphone - A simple program to convert text to uppercase
- **ex01**: PhoneBook - A simple phonebook application
- **ex02**: The Job Of Your Dreams

### Cpp01
Memory allocation, pointers to members, references, switch statement.

- **ex00**: BraiiiiiiinnnzzzZ - Zombie class implementation
- **ex01**: Moar brainz! - Zombie horde
- **ex02**: HI THIS IS BRAIN - References and pointers
- **ex03**: Unnecessary violence - Weapon class with references
- **ex04**: Sed is for losers - File manipulation
- **ex05**: Harl 2.0 - Pointers to member functions
- **ex06**: Harl filter - Switch statement

### Cpp02
Ad-hoc polymorphism, operator overloading, and Orthodox Canonical class Form.

- **ex00**: My First Class in Orthodox Canonical Form
- **ex01**: Towards a more useful fixed-point number class
- **ex02**: Now we're talking - Operator overloading

### Cpp03
Inheritance in C++.

- **ex00**: Aaaaand... OPEN! - ClapTrap class
- **ex01**: Serena, my love! - ScavTrap derived class
- **ex02**: Repetitive work - FragTrap derived class
- **ex03**: Now it's weird! - DiamondTrap (multiple inheritance)

## Build

Each exercise contains a Makefile. To compile an exercise:

```bash
cd CppXX/exXX
make
```

### Makefile targets

- `make` or `make all` - Compile the program
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Recompile everything
- `make debug` - Clean rebuild with debug flags (address sanitizer)

## Requirements

- C++ compiler (c++)
- C++98 standard
- Make

## Author

alexBickle24
