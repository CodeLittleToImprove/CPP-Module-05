/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:58:22 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/07/15 19:58:25 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Default constructor
AForm::AForm()
	:_name("Default Form"), _signGrade(150), _executeGrade(150), _isSigned(false)
{
//	std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
AForm::AForm(const std::string &name, unsigned int signGrade, unsigned int executeGrade)
	:_name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false)
{
	// std::cout << "Parameterized constructor called" << std::endl;
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
}

// Copy constructor
AForm::AForm(const AForm& other)
	:_name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade), _isSigned(other._isSigned)
{
//	std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignment operator overload
AForm& AForm::operator=(const AForm& other)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

// Destructor
AForm::~AForm(void)
{
//	std::cout << "Destructor called" << std::endl;
}

const std::string& AForm::getName() const
{
	return (_name);
}

unsigned int AForm::getSignGrade() const
{
	return (_signGrade);
}

unsigned int AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

void AForm::beSigned(Bureaucrat& signer)
{
	if (signer.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& a)
{
	os << "\033[36m"
	<< "Form name: " << a.getName() << std::endl
	<< "SignGrade: " << a.getSignGrade() <<std::endl
	<< "ExecuteGrade :" << a.getExecuteGrade() << std::endl
	<< "IsSigned: " << std::boolalpha << a.getIsSigned() << std::endl
	<< "\033[0m";  // Reset color
	return (os);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("\033[1;31mGrade too high\033[0m");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("\033[1;31mGrade too low\033[0m");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("\033[1;31mForm not signed \033[0m");
}
