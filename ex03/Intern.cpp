/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:58:36 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/07/15 19:58:38 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Default constructor
Intern::Intern()
{
	// std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern& other)
{
	(void)other;
	// std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignment operator overload
Intern& Intern::operator=(const Intern& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

// Destructor
Intern::~Intern(void)
{
	// std::cout << "Destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	std::string formNames[3] =
{
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	int i;
	for (i = 0; i < 3; ++i)
	{
		if (formNames[i] == formName)
			break;
	}
	switch(i)
	{
		case 0:
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (new PresidentialPardonForm(target));
		case 1:
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "Intern cannot create form: " << formName << std::endl;
			return (NULL);
	}
}

