cmake_minimum_required(VERSION 3.29)
project(cpp05)

set(CMAKE_CXX_STANDARD 98)


add_executable(cpp05_ex00
        ex00/main.cpp
        ex00/Bureaucrat.cpp
        ex00/Bureaucrat.hpp
)

add_executable(cpp05_ex01
        ex01/main.cpp
        ex01/Bureaucrat.cpp
        ex01/Bureaucrat.hpp
        ex01/Form.cpp
        ex01/Form.hpp
)

add_executable(cpp05_ex02
        ex02/main.cpp
        ex02/Bureaucrat.cpp
        ex02/Bureaucrat.hpp
        ex02/AForm.cpp
        ex02/AForm.hpp
        ex02/PresidentialPardonForm.hpp
        ex02/PresidentialPardonForm.cpp
        ex02/RobotomyRequestForm.hpp
        ex02/RobotomyRequestForm.cpp
)
#add_executable(cpp04_ex01
#        ex01/Animal.cpp
#        ex01/Brain.cpp
#        ex01/Cat.cpp
#        ex01/Dog.cpp
#        ex01/main.cpp)
#
#add_executable(cpp04_ex02
#        ex02/AAnimal.cpp
#        ex02/Brain.cpp
#        ex02/Cat.cpp
#        ex02/Dog.cpp
#        ex02/main.cpp)