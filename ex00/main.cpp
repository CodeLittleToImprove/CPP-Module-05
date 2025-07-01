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
		std::cout << "\033[33m[Exception] Incrementing grade of " << a.getName()
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
		std::cout << "\033[33m[Exception] Decrementing grade of " << b.getName()
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
		std::cout << "\033[33m[Exception] Decrementing grade of " << c.getName()
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


int main(void)
{
	try
	{
		runFirstTest();
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Unexpected error during First Test" << std::endl;
	}
	std::cout  << std::endl;
	try
	{
		runSecondTest();
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Unexpected error during Second Test" << std::endl;
	}
	std::cout  << std::endl;
	try
	{
		runThirdTest();
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Unexpected error during Third Test" << std::endl;
	}
	std::cout  << std::endl;
	try
	{
		runFourthTest();
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Unexpected error during Third Test" << std::endl;
	}
	std::cout  << std::endl;
	try
	{
		runFifthTest();
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Unexpected error during Fifth Test" << std::endl;
	}
}

//
// 		std::cout << a;
//
// 		try
// 		{
// 			a->decrementGrade();
// 		}
// 		catch (Bureaucrat::GradeTooLowException& e)
// 		{
// 			std::cerr << "\033[33mDecrementing grade of " << a->getName() <<
// 				" failed: " << e.what() << "\033[0m" << std::endl;
// 		}
//
// 		std::cout << a;
// 		std::cout << std::endl;
//
// 		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
// 		delete a;
// 		std::cout << std::endl;
// 	}
// 	std::cout << "-------------------------------------------------------" << std::endl;
// 	{
// 		std::cout << std::endl;
// 		std::cout << "\033[34mConstructing\033[0m" << std::endl;
// 		Bureaucrat* a = new Bureaucrat(1);
// 		std::cout << std::endl;
// 		std::cout << "\033[34mTesting\033[0m" << std::endl;
// 		std::cout << a;
//
// 		try
// 		{
// 			a->decrementGrade();
// 		}
// 		catch (Bureaucrat::GradeTooLowException& e)
// 		{
// 			std::cerr << "\033[33mDecrementing grade of " << a->getName() <<
// 				" failed: " << e.what() << "\033[0m" << std::endl;
// 		}
//
// 		std::cout << a;
//
// 		try
// 		{
// 			a->incrementGrade();
// 		}
// 		catch (Bureaucrat::GradeTooHighException& e)
// 		{
// 			std::cerr << "\033[33mIncrementing grade of " << a->getName() <<
// 				" failed: " << e.what() << "\033[0m" << std::endl;
// 		}
//
// 		std::cout << a;
//
// 		try
// 		{
// 			a->incrementGrade();
// 		}
// 		catch (Bureaucrat::GradeTooHighException& e)
// 		{
// 			std::cerr << "\033[33mIncrementing grade of " << a->getName() <<
// 				" failed: " << e.what() << "\033[0m" << std::endl;
// 		}
//
// 		std::cout << a;
// 		std::cout << std::endl;
//
// 		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
// 		delete a;
// 		std::cout << std::endl;
// 	}
// 	std::cout << "-------------------------------------------------------" << std::endl;
// 	{
// 		std::cout << std::endl;
// 		std::cout << "\033[34mConstructing\033[0m" << std::endl;
// 		Bureaucrat* a = NULL;
//
// 		try
// 		{
// 			a = new Bureaucrat(0);
// 		}
// 		catch (Bureaucrat::GradeTooHighException& e)
// 		{
// 			std::cerr << "\033[33mConstructing default failed: " <<
// 				e.what() << "\033[0m" << std::endl;
// 		}
//
// 		if (a != NULL)
// 		{
// 			std::cout << std::endl;
//
// 			std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
// 			delete a;
// 		}
//
// 		std::cout << std::endl;
// 	}
// 	std::cout << "-------------------------------------------------------" << std::endl;
// 	{
// 		std::cout << std::endl;
// 		std::cout << "\033[34mConstructing\033[0m" << std::endl;
// 		Bureaucrat* a = NULL;
//
// 		try
// 		{
// 			a = new Bureaucrat(160);
// 		}
// 		catch (Bureaucrat::GradeTooLowException& e)
// 		{
// 			std::cerr << "\033[33mConstructing default failed: " <<
// 				e.what() << "\033[0m" << std::endl;
// 		}
//
// 		if (a != NULL)
// 		{
// 			std::cout << std::endl;
// 			std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
// 			delete a;
// 		}
// 		std::cout << std::endl;
// 	}
// 	std::cout << "-------------------------------------------------------" << std::endl;
// 	{
// 		std::cout << std::endl;
// 		std::cout << "\033[34mConstructing\033[0m" << std::endl;
// 		Bureaucrat* a = new Bureaucrat("Peter", 120);
// 		std::cout << std::endl;
//
// 		std::cout << "\033[34mTesting a\033[0m" << std::endl;
// 		std::cout << a;
//
// 		a->decrementGrade();
//
// 		std::cout << a;
// 		std::cout << std::endl;
//
// 		std::cout << "\033[34mConstructing b\033[0m" << std::endl;
// 		Bureaucrat* b = new Bureaucrat(*a);
// 		std::cout << std::endl;
//
// 		std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
// 		delete a;
// 		std::cout << std::endl;
//
// 		std::cout << "\033[34mTesting b\033[0m" << std::endl;
// 		std::cout << b;
// 		b->decrementGrade();
// 		std::cout << b;
// 		std::cout << std::endl;
//
// 		std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
// 		delete b;
//
// 		std::cout << std::endl;
// 	}
// }
