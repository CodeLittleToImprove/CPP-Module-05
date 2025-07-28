/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:11:14 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/04/24 17:44:30 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void printHeader(const std::string& title, const std::string& description, const std::string& expected)
{
	std::cout << "\n\033[34m========== " << title << " ==========\033[0m\n";
	std::cout << "\033[1;34mTest: " << description << "\033[0m\n";
	std::cout << "\033[1;34mExpected: " << expected << "\033[0m\n";
}

void printException(const std::exception& e)
{
	std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
}

void runInternPresidentialPardonFormTest ()
{
	printHeader(
		"Intern PresidentialPardonForm Test",
		"Create a PresidentialPardonForm with Intern and sign and execute it",
		"Should create a PresidentialPardonForm with Intern "
	);

	Intern internA;
	Bureaucrat top("TopBureaucrat", 1);
	AForm *presidentalPardonForm = internA.makeForm("presidential pardon", "FormName1");
	try
	{

		presidentalPardonForm->beSigned(top);
		presidentalPardonForm->execute(top);
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

void runInternRobotomyTest()
{
	std::srand(std::time(NULL));
	printHeader(
		"Intern Robotomy Test",
		"Create a RobotomyRequestForm with Intern and sign and execute it",
		"Should print drilling noise and either success or failure (random)"
	);

	Intern intern;
	Bureaucrat top("TopBureaucrat", 1);
	AForm* robotomyForm = intern.makeForm("robotomy request", "TestSubject");

	try
	{
		robotomyForm->beSigned(top);
		robotomyForm->execute(top);
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

void runInternShrubberyTest()
{
	printHeader(
		"Intern Shrubbery Test",
		"Create a ShrubberyCreationForm with Intern and sign and execute it",
		"Should create a file named <target>_shrubbery with an ASCII tree"
	);

	Intern intern;
	Bureaucrat top("TopBureaucrat", 1);
	AForm* shrubberyForm = intern.makeForm("shrubbery creation", "MyGarden");

	try
	{
		shrubberyForm->beSigned(top);
		shrubberyForm->execute(top);
		std::cout << "\033[32mSuccess: File 'MyGarden_shrubbery' should now exist.\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

void runInternInvalidFormTest()
{
	printHeader(
		"Intern Invalid Form Test",
		"Try to create an unknown form with Intern",
		"Should print error message and return NULL"
	);

	Intern intern;
	AForm* unknownForm = intern.makeForm("unknown form", "Nowhere");

	if (!unknownForm)
		std::cout << "\033[31mError: Intern could not create unknown form.\033[0m" << std::endl;
	else
		std::cout << "\033[31mUnexpected: Form was created.\033[0m" << std::endl;
}

int main(void)
{

	runInternPresidentialPardonFormTest();
	runInternRobotomyTest();
	runInternShrubberyTest();
	runInternInvalidFormTest();
}

