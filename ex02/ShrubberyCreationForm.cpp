/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:58:22 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/07/15 19:58:25 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
	:AForm("ShrubberyCreationForm", 145, 137), _target("Default target")
{
//	std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
//	std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignment operator overload
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other); // copy base class members
		this->_target= other._target; // copy derived class members
	}
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
//	std::cout << "Destructor called" << std::endl;
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw ShrubberyCreationForm::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw ShrubberyCreationForm::FormNotSignedException();
	std::string target = this->_target + "_shrubbery";
	std::ofstream	output(target.c_str());

	if (!output.is_open())
		throw ShrubberyCreationForm::FailInFileException();
	output << "       _-_" << std::endl;
	output << "    /~~   ~~" << std::endl;
	output << " /~~         ~~" << std::endl;
	output << "{               }" << std::endl;
	output << " \\  _-     -_  /" << std::endl;
	output << "   ~  \\\\ //  ~" << std::endl;
	output << "_- -   | | _- _" << std::endl;
	output << "  _ -  | |   -_" << std::endl;
	output << "      // \\\\ " << std::endl;
	// output.flush();
	// output.close();
	std::cout << "done Shrubbery Execute" << std::endl;
}

const char *ShrubberyCreationForm::FailInFileException::what() const throw()
{
	return "\033The file failed to open or to be created!\033[0m";
}