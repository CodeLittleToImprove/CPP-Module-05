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
	std::cout << "\033[34mFirst Test\033[0m" << std::endl;
	Bureaucrat a;
	std::cout << "value before call incrementGrade: " << std::endl << a << std::endl;

	try
	{
		a.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "\033[33mIncrementing grade of " << a.getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "value after call incrementGrade: " << std::endl << a << std::endl;
}

void runSecondTest()
{
	std::cout << "\033[34mSecond Test\033[0m" << std::endl;
	Bureaucrat b;
	std::cout << "value before call decrementGrade: " << std::endl << b << std::endl;

	try
	{
		b.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "\033[33mDecrementing grade of " << b.getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "value after call decrementGrade: " << std::endl << b << std::endl;
}

void runThirdTest()
{
	std::cout << "\033[34mThird Test\033[0m" << std::endl;
	Bureaucrat c(150);
	std::cout << "value before call decrementGrade: " << std::endl << c << std::endl;

	try
	{
		c.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "\033[33mDecrementing grade of " << c.getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "value after call decrementGrade: " << std::endl << c << std::endl;
}

void runFourthTest()
{
	std::cout << "\033[34mFourth Test\033[0m" << std::endl;

	try
	{
		Bureaucrat d("David", 160); // does not throw an exception and just stops?
		std::cout << "value before call decrementGrade: " << std::endl << d << std::endl;
		d.decrementGrade();
		std::cout << "value after call decrementGrade: " << std::endl << d << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "\033[33mCreating Bureaucrat 'David' failed: "
			<< e.what() << "\033[0m" << std::endl;
	}
}

void runFifthTest()
{
	std::cout << "\033[34mFifth Test\033[0m" << std::endl;

	try
	{
		Bureaucrat e("Eve", 0); // Too high
		std::cout << "value before call incrementGrade: " << std::endl << e << std::endl;
		e.incrementGrade();
		std::cout << "value after call incrementGrade: " << std::endl << e << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "\033[33mCreating Bureaucrat 'Eve' failed: "
			<< e.what() << "\033[0m" << std::endl;
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

	try
	{
		runSecondTest();
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Unexpected error during Second Test" << std::endl;
	}

	try
	{
		runThirdTest();
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Unexpected error during Third Test" << std::endl;
	}

	try
	{
		runFourthTest();
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Unexpected error during Third Test" << std::endl;
	}

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
