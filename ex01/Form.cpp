
#include "Form.hpp"

// Default constructor
Form::Form()
	:_name("Default Form"), _signGrade(150), _executeGrade(150), _isSigned(false)
{
//	std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
Form::Form(const std::string &name, unsigned int signGrade, unsigned int executeGrade)
	:_name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false)
{
	// std::cout << "Parameterized constructor called" << std::endl;
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
}

// Copy constructor
Form::Form(const Form& other)
	:_name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade), _isSigned(other._isSigned)
{
//	std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignment operator overload
Form& Form::operator=(const Form& other)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

// Destructor
Form::~Form(void)
{
//	std::cout << "Destructor called" << std::endl;
}

const std::string& Form::getName() const
{
	return (_name);
}

const unsigned int Form::getSignGrade() const
{
	return (_signGrade);
}

const unsigned int Form::getExecuteGrade() const
{
	return (_executeGrade);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

void Form::beSigned(Bureaucrat& signer)
{
	if (signer.getGrade() >= this->_signGrade)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& a)
{
	os << "FormName:" << a.getName() << "\nIsSigned:" << a.getIsSigned() <<  "\nSignGrade:" << a.getSignGrade() << "\nExecuteGrade:" << a.getExecuteGrade() << std::endl;
	return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("\033[1;31mGrade too high\033[0m");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("\033[1;31mGrade too low\033[0m");
}