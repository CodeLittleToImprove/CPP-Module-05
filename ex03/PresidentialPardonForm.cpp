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

#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm()
	:AForm("PresidentialPardonForm", 25, 5), _target("Default target")
{
//	std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon Form", 25, 5), _target(target)
{
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target)
{
//	std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignment operator overload
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
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
PresidentialPardonForm::~PresidentialPardonForm(void)
{
//	std::cout << "Destructor called" << std::endl;
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

// void PresidentialPardonForm::execute(Bureaucrat const& executor) const
// {
//
//
// }

void PresidentialPardonForm::executeAction() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
