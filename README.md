


<img src="assets/ISO_C++_Logo.svg.png" width="300" alt="400" /> <img src="assets/solid.png" width="500" alt="500" />

# C++ Modules

This repository contains solutions for the 42 school C++ modules (Cpp00 - Cpp04).

## Modules



### Cpp00

**Introduction to C++ basics: namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff.**


#### Generic concepts

- Class concept
- Object concept
- Abstraction and encapsulation
- Public and private attributes
- What are references
- Basic use of streams and classes from the std namespace
- Use of string objects
- Scope operators for class method definitions from another file
- What are constructors and initialization lists
- Use of the this clause
- Use of static attributes and the concept of not belonging to any object
- Static methods, which are the only ones that can modify static variables
- Arrays of objects
- Basic composition concept

#### Exercises

- **ex00**: Megaphone - A simple program to convert text to uppercase
- **ex01**: PhoneBook - A simple phonebook application
- **ex02**: The Job Of Your Dreams



### Cpp01

**Memory allocation, pointers to members, references, switch statement.**

#### Generic concepts

- Dynamic memory allocation with new
- Destroying dynamic memory with delete
- Arrays of objects with default constructor
- Class destructor concept
- Using stringstream to simulate base changes
- Concept of references and differences with pointers
- References passed as parameters to avoid memory duplication
- Pointers to point to objects from an external object without owning them
- References to point to external objects but associated with the class itself
- Using fstream class and string class method to convert to char *
- getline function
- Function pointers and arrays of function pointers (notations)
- Use of switch (internally uses jump tables or binary trees to keep O(1) complexity)

#### Exercises

- **ex00**: BraiiiiiiinnnzzzZ - Zombie class implementation
- **ex01**: Moar brainz! - Zombie horde
- **ex02**: HI THIS IS BRAIN - References and pointers
- **ex03**: Unnecessary violence - Weapon class with references
- **ex04**: Sed is for losers - File manipulation
- **ex05**: Harl 2.0 - Pointers to member functions
- **ex06**: Harl filter - Switch statement



### Cpp02

**Ad-hoc polymorphism, operator overloading, and Orthodox Canonical class Form.**

#### Generic concepts

- What are fixed point numbers and why are they used for determinism across different processor architectures regardless of FPU presence
- How they are created with bit shifting and how operations are performed with fixed point numbers
- Construction of orthodox canonical classes (default constructor, copy constructor, default destructor, and overloaded assignment operator to avoid bitwise copy or shallow copy)
- Compile-time polymorphism or ad-hoc polymorphism
- Overloaded operators for direct arithmetic and logical operations between objects
- Overloading operator for ofstream object to print to screen/stdout redirections
- Overloaded operators for post-increment and pre-increment operations on numbers
- Why you should return objects directly in overloaded arithmetic operations but return references in assignment operations (+=, -=, etc.)

#### Exercises

- **ex00**: My First Class in Orthodox Canonical Form
- **ex01**: Towards a more useful fixed-point number class
- **ex02**: Now we're talking - Operator overloading



### Cpp03

**Inheritance in C++.**

#### Generic concepts

- Inheritance
- Inheritance of public, protected, and private attributes
- No inheritance of overloaded operators, constructors, and destructors
- Memory of the base class and the derived class
- Destruction order of an object built through a base class
- What is the virtual table and why it enables polymorphism
- Why base class destructors should be virtual to avoid memory leaks in polymorphism
- Calling base class constructors from the derived class to build the base part
- Avoid calling base class constructors from derived classes if the base has a default constructor
- Dynamic vs static polymorphism (concept)
- Memory overhead due to the virtual table
- What is object slicing
- Using pointers and references to the base class for virtual method polymorphism in function parameters and class methods
- What is object slicing and why you can't assign a derived object to a base object
- Inheritance as specialization and composition for scalable class systems
- Diamond classes and why you must inherit from the base class virtually to avoid duplicating the base part in the diamond class
- Diamond class constructors must call the base class constructor

#### Exercises

- **ex00**: Aaaaand... OPEN! - ClapTrap class
- **ex01**: Serena, my love! - ScavTrap derived class
- **ex02**: Repetitive work - FragTrap derived class
- **ex03**: Now it's weird! - DiamondTrap (multiple inheritance)



### Cpp04

**Subtype polymorphism, abstract classes and interfaces.**


#### Generic concepts

- Polymorphism and memory scopes in polymorphism
- Attribute hiding (shadowing)
- Array of references notations in function parameters and return types
- Shallow copy vs deep copy for dynamic memory
- Abstract classes (non-instantiable but serve as base for polymorphism)
- Interfaces or pure abstract classes
- Non-constructible: serve as base for pointers and references in polymorphism
- Class composition and circular dependencies
- Const references as return values in getters to save memory and ensure attribute encapsulation

#### Exercises

- **ex00**: Polymorphism - Animal, Dog, Cat classes with virtual functions
- **ex01**: I don't want to set the world on fire - Adding Brain class for deep copy
- **ex02**: Abstract class - Animal as an abstract class with pure virtual function
- **ex03**: Interface & recap - Materia system with interfaces (AMateria, ICharacter, IMateriaSource)

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

alcarril
