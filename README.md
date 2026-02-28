<img src="assets/ISO_C++_Logo.svg.png" width="300" alt="400" /> <img src="assets/solid.png" width="500" alt="500" />

# C++ Modules

This repository contains solutions for the 42 school C++ modules (Cpp00 - Cpp09).




## Cpp00

**Introduction to C++ basics: namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff.**

#### Exercises

- **ex00**: [Megaphone - A simple program to convert text to uppercase](Cpp00/ex00/)
- **ex01**: [PhoneBook - A simple phonebook application](Cpp00/ex01/)
- **ex02**: [The Job Of Your Dreams](Cpp00/ex02/)

<details>
<summary>Generic concepts</summary>

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

</details>



## Cpp01

**Memory allocation, pointers to members, references, switch statement.**

#### Exercises

- **ex00**: [BraiiiiiiinnnzzzZ - Zombie class implementation](Cpp01/ex00/)
- **ex01**: [Moar brainz! - Zombie horde](Cpp01/ex01/)
- **ex02**: [HI THIS IS BRAIN - References and pointers](Cpp01/ex02/)
- **ex03**: [Unnecessary violence - Weapon class with references](Cpp01/ex03/)
- **ex04**: [Sed is for losers - File manipulation](Cpp01/ex04/)
- **ex05**: [Harl 2.0 - Pointers to member functions](Cpp01/ex05/)
- **ex06**: [Harl filter - Switch statement](Cpp01/ex06/)

<details>
<summary>Generic concepts</summary>

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

</details>



## Cpp02

**Ad-hoc polymorphism, operator overloading, and Orthodox Canonical class Form.**

#### Exercises

- **ex00**: [My First Class in Orthodox Canonical Form](Cpp02/ex00/)
- **ex01**: [Towards a more useful fixed-point number class](Cpp02/ex01/)
- **ex02**: [Now we're talking - Operator overloading](Cpp02/ex02/)

<details>
<summary>Generic concepts</summary>

- What are fixed point numbers and why are they used for determinism across different processor architectures regardless of FPU presence
- How they are created with bit shifting and how operations are performed with fixed point numbers
- Construction of orthodox canonical classes (default constructor, copy constructor, default destructor, and overloaded assignment operator to avoid bitwise copy or shallow copy)
- Compile-time polymorphism or ad-hoc polymorphism
- Overloaded operators for direct arithmetic and logical operations between objects
- Overloading operator for ofstream object to print to screen/stdout redirections
- Overloaded operators for post-increment and pre-increment operations on numbers
- Why you should return objects directly in overloaded arithmetic operations but return references in assignment operations (+=, -=, etc.)

</details>


## Cpp03

**Inheritance in C++.**

#### Exercises

- **ex00**: [Aaaaand... OPEN! - ClapTrap class](Cpp03/ex00/)
- **ex01**: [Serena, my love! - ScavTrap derived class](Cpp03/ex01/)
- **ex02**: [Repetitive work - FragTrap derived class](Cpp03/ex02/)
- **ex03**: [Now it's weird! - DiamondTrap (multiple inheritance)](Cpp03/ex03/)

<details>
<summary>Generic concepts</summary>

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

</details>



## Cpp04

**Subtype polymorphism, abstract classes and interfaces.**

#### Exercises

- **ex00**: [Polymorphism - Animal, Dog, Cat classes with virtual functions](Cpp04/ex00/)
- **ex01**: [I don't want to set the world on fire - Adding Brain class for deep copy](Cpp04/ex01/)
- **ex02**: [Abstract class - Animal as an abstract class with pure virtual function](Cpp04/ex02/)
- **ex03**: [Interface & recap - Materia system with interfaces (AMateria, ICharacter, IMateriaSource)](Cpp04/ex03/)

<details>
<summary>Generic concepts</summary>

- Polymorphism and memory scopes in polymorphism
- Attribute hiding (shadowing)
- Array of references notations in function parameters and return types
- Shallow copy vs deep copy for dynamic memory
- Abstract classes (non-instantiable but serve as base for polymorphism)
- Interfaces or pure abstract classes
- Non-constructible: serve as base for pointers and references in polymorphism
- Class composition and circular dependencies
- Const references as return values in getters to save memory and ensure attribute encapsulation

</details>


## Cpp05

**Exceptions.**


#### Exercises

- **ex00**: [Bureaucrat - Implementation of a Bureaucrat class with grade validation and exception handling](Cpp05/ex00/)
- **ex01**: [Form - Adding a Form class that interacts with the Bureaucrat class, including signing functionality](Cpp05/ex01/)
- **ex02**: [Advanced Forms - Introduction of abstract forms (AForm) and specific form types like PresidentialPardonForm, RobotomyRequestForm, and ShrubberyCreationForm](Cpp05/ex02/)
- **ex03**: [Intern - Implementation of an Intern class that can create forms dynamically based on input](Cpp05/ex03/)

<details>
<summary>Generic concepts</summary>

- How `try`, `throw`, and `catch` clauses work.
- Types of data that can be thrown with `throw`, the `std::exception` class, and why it is recommended to throw objects.
- What happens when an exception is thrown but not caught: **(segfault) → std::terminate()**
- Memory scope of the `try` block: Objects created inside a `try` block have a local memory scope. When exiting the block due to an exception or normal execution, **stack unwinding** occurs, automatically destroying local objects. To preserve them, use pointers and dynamic memory.
- Classes inheriting from `std::exception` and types of errors.
- How to configure custom exceptions within classes by creating nested classes that inherit from `std::exception` and overriding the `what()` method for polymorphism. Why it is not a good idea to convert a normal class into an exception.
- Why methods overriding `std::exception` methods should use the `throw()` clause to specify that the method will not throw another exception.
- Nested classes are not constructed by default when using the constructor of the external class. They must be initialized in methods. Principles of nested class usage: **Cohesion Principle and Single Responsibility.**

</details>

<details>
<summary>Best Practices</summary>

- Constructors that may throw errors due to invalid attribute values should only throw the error. The `try` and `catch` should be handled in `main` to avoid partially created objects in memory, which could lead to segmentation faults or undefined behavior.
- Methods can have their own `try` and `catch` blocks for cleaner code.
- Nested `try` blocks are possible but not clean. If an exception is thrown in the outer `try`, the inner block will not execute, and exceptions will not be lost.
- When a base class defines its own errors and has methods overridden with polymorphism in derived classes, it is good practice to:
  - Throw base class errors from the base class methods.
  - In derived class methods, call the base class method to check for base errors, then handle specific errors in the derived class.
  - Throw different types of objects for different errors to avoid confusion in `catch` blocks.
- When functions or methods with `try` blocks call other functions or methods with their own `try` blocks, exceptions thrown in the lower-level function may be caught there, causing the higher-level code to not behave as expected. In such cases, it is important that the `try` and `catch` blocks are always in the higher-level function, while the lower-level function should only contain `throw` statements ot throw objects of different types for different errors.

</details>



## Cpp06

**C++ casts and static_assert.**


#### Exercises

- **ex00**: [Char* to Numeric Conversion - Using std::strtod and static_cast for type conversion](Cpp06/ex00/)
- **ex01**: [Serialization and Deserialization - Using `reinterpret_cast` for pointer manipulation](Cpp06/ex01/)
- **ex02**: [Dynamic Cast - Checking pointers in polymorphic class hierarchies](Cpp06/ex02/)

<details>
<summary>Generic concepts</summary>

- Types of casts in C++: `reinterpret_cast`, `static_cast`, `dynamic_cast`, and `const_cast`
  - **`static_cast`**:
    - Used for safe conversions between compatible types.
    - Respects strict aliasing rules.
    - Useful for upcasting and downcasting in class hierarchies without virtual functions.
  - **`reinterpret_cast`**:
    - Reinterprets the bits of memory regions.
    - Does not respect type compatibility and breaks strict aliasing rules.
    - Used for:
      - Conversions between pointers of different class types.
      - Serialization.
      - Systems programming.
      - Accessing memory-mapped regions.
      - Drivers.
      - Bootloaders.
      - Embedded systems.
  - **`dynamic_cast`**:
    - Runtime type casting.
    - Used for polymorphic class hierarchies with virtual functions.
    - Behavior:
      - For pointers: Performs downcasting and returns `nullptr` if the cast fails.
      - For references: Throws exceptions of type `std::bad_cast` (derived from `std::exception`) if the cast fails.
- Serialization and deserialization: standardization across different systems
- Why `uintptr_t` can be used to represent pointers (`void*`): portability across systems with different architectures, serialization of types
- Methods for converting `char*` to numeric types and parsing:
  - `std::stringstream` from `<sstream>`
  - `atoi`, `atol`, and `atof` from `<cstdlib>`
  - `strtol`, `strtoll`, and `strtod` from `<cstdlib>`
- `is` functions in C++ from `<cctype>`, `<cmath>`, and `<cfloat>`
- `limits` functions from `<climits>` and `<limits>`
- Base conversions
- How to generate random numbers (seed + sequence)

</details>



## Cpp07

**Templates and iterators.**


#### Exercises

- **ex00**: [Template Functions - Creating functions using templates for generic data types, pointers, and references](Cpp07/ex00/)
- **ex01**: [Iter Function Template - Implementing a template function that accepts generic types, including const and non-const pointers](Cpp07/ex01/)
- **ex02**: [Template Array Class - Creating a template-based array class with const and non-const instantiations, overloaded operators, and exception handling](Cpp07/ex02/)

<details>
<summary>Generic concepts</summary>

- What are templates in C++ and why they are used
- Templates and type deduction:
  - Function parameter templates:
    - Templates with multiple function parameters.
    - Templates with constant values and constant types.
    - Specialized templates (specialized data types).
  - Function templates (callbacks):
    - Explicit declaration: function type (return and arguments are generic data).
    - Implicit declaration (generic).
    - Calling a template function with an argument that is not another template function (template callbacks).
  - Memory address templates:
    - When a generic data template allows memory addresses to be passed (cannot dereference inside the template function).
    - When the template declaration specifies that the generic type is a pointer `function(T* ptr)`, dereferencing is allowed, but the compiler only accepts pointers.
    - It is also possible to specify in the template function declaration that it is a reference or a pointer to a reference.
  - Const data templates (const-correctness):
    - When it is a generic function declaration and a const or non-const data is passed, it does not matter because a copy is made in the memory stack with the data as non-const (passing parameters by value).
    - When it is a generic declaration with a reference, if the data passed is a reference, it directly points to the variable passed. If it is const, it remains const; if not, it does not remain const (passing parameters by reference).
    - When it is specified in the parameter that it is a memory address, the const behaves like references: if the data was const, it remains const; if not, it does not remain const (passing by reference).
    - When it is specified in the template that the generic data will be treated as `const T data`, if the parameter entered is non-const, it is treated as non-const; if it was const, it is also treated as const.
- Class templates:
  - How to create a class template.
  - Method declarations must be in the `.h` file.
  - Methods that return a template-type object can be declared with return type `Object&` or `Object<templatealias>&`.
  - When instantiating a template-type object, it must be instantiated with `ObjectName<datatype> alias(constructor)`.
  - When we want the template object to have its generic elements as const, it must be declared as `const ObjectName<datatype> alias(constructor)`.
- Overloading the array index access operator within objects.
- Class hierarchy for inheritance: `std::out_of_range`.

</details>


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