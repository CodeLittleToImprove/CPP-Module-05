
#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat()
	:_name("Default"), _grade(1)
{
	// std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(int grade)
	:_name("Default"), _grade(grade)
{
	// std::cout << "Parameterized constructor called" << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	:_name(name), _grade()
{
	// std::cout << "Parameterized constructor called" << std::endl;
	this->setGrade(grade);
}
// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:_name(other._name), _grade(other._grade)
{
	// std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignment operator overload
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
	// std::cout << "Destructor called" << std::endl;
}

const std::string& Bureaucrat::getBureaucratName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

void Bureaucrat::incrementGrade()
{
	this->setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	this->setGrade(this->_grade + 1);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& a)
{
	os << "\033[36m"
	<< "Bureaucrat" << " name: " << a.getBureaucratName() << " grade: " << a.getGrade()
	<< "\033[0m";  // Reset color
	return os;
}
