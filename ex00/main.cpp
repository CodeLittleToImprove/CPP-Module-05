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

void runFirstTest()
{
	std::cout << "\n\033[34m========== First Test ==========\033[0m\n";
	std::cout << "\033[1;34mTest: Increment grade at highest level\033[0m\n";
	std::cout << "\033[1;34mExpected: Should throw GradeTooHighException\033[0m\n";

	Bureaucrat a;
	std::cout << "\n\033[36m[Before incrementGrade()]\033[0m\n" << a << std::endl;

	try
	{
		a.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "\033[33m[Exception] Incrementing grade of " << a.getBureaucratName()
			<< " failed: " << e.what() << "\033[0m\n";
	}

	std::cout << "\n\033[36m[After incrementGrade()]\033[0m\n" << a << std::endl;
}

void runSecondTest()
{
	std::cout << "\n\033[34m========== Second Test ==========\033[0m\n";
	std::cout << "\033[1;34mTest: Decrement grade from 1 to 2\033[0m\n";
	std::cout << "\033[1;34mExpected: Grade should decrease normally\033[0m\n";

	Bureaucrat b;
	std::cout << "\n\033[36m[Before decrementGrade()]\033[0m\n" << b << std::endl;

	try
	{
		b.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "\033[33m[Exception] Decrementing grade of " << b.getBureaucratName()
			<< " failed: " << e.what() << "\033[0m\n";
	}

	std::cout << "\n\033[36m[After decrementGrade()]\033[0m\n" << b << std::endl;
}

void runThirdTest()
{
	std::cout << "\n\033[34m========== Third Test ==========\033[0m\n";
	std::cout << "\033[1;34mTest: Decrement grade at lowest level (150)\033[0m\n";
	std::cout << "\033[1;34mExpected: Should throw GradeTooLowException\033[0m\n";

	Bureaucrat c(150);
	std::cout << "\n\033[36m[Before decrementGrade()]\033[0m\n" << c << std::endl;

	try
	{
		c.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "\033[33m[Exception] Decrementing grade of " << c.getBureaucratName()
			<< " failed: " << e.what() << "\033[0m\n";
	}

	std::cout << "\n\033[36m[After decrementGrade()]\033[0m\n" << c << std::endl;
}

void runFourthTest()
{
	std::cout << "\n\033[34m========== Fourth Test ==========\033[0m\n";
	std::cout << "\033[1;34mTest: Create Bureaucrat with grade 160\033[0m\n";
	std::cout << "\033[1;34mExpected: Should throw GradeTooLowException\033[0m\n";

	try
	{
		Bureaucrat d("David", 160);
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "\033[33m[Exception] Creating Bureaucrat 'David' failed: "
			<< e.what() << "\033[0m\n";
	}
}

void runFifthTest()
{
	std::cout << "\n\033[34m========== Fifth Test ==========\033[0m\n";
	std::cout << "\033[1;34mTest: Create Bureaucrat with grade 0\033[0m\n";
	std::cout << "\033[1;34mExpected: Should throw GradeTooHighException\033[0m\n";

	try
	{
		Bureaucrat e("Eve", 0);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "\033[33m[Exception] Creating Bureaucrat 'Eve' failed: "
			<< e.what() << "\033[0m\n";
	}
}

void runSixthTest()
{
	std::cout << "\n\033[34m========== SIXTH Test ==========\033[0m\n";
	std::cout << "\033[1;34mTest: Create Bureaucrat with grade 1 and copy it and then increase the grade of the copy by one\033[0m\n";
	std::cout << "\033[1;34mExpected: Should throw GradeTooHighException\033[0m\n";
	Bureaucrat e("Eve", 1);
	Bureaucrat f(e);
	try
	{
		f.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "\033[33m[Exception] Creating Bureaucrat 'Eve' failed: "
			<< e.what() << "\033[0m\n";
	}
}
int main(void)
{
		runFirstTest();
		runSecondTest();
		runThirdTest();
		runFourthTest();
		runFifthTest();
		runSixthTest();
}
