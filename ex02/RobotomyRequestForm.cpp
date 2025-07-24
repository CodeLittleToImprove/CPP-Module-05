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

#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
	:AForm("RobotomyRequestForm", 72, 45), _target("Default target")
{
//	std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
//	std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignment operator overload
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
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
RobotomyRequestForm::~RobotomyRequestForm(void)
{
//	std::cout << "Destructor called" << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw RobotomyRequestForm::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw RobotomyRequestForm::FormNotSignedException();
	std::cout << "Doriru Doriru Doriru Doriru ..." << std::endl;
	int n = std::rand();
	if (n % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomy failed.." << std::endl;
}
