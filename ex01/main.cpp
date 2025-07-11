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
	std::cout << "\033[1;34mTest: Create a form in a valid range and print it \033[0m\n";
	std::cout << "\033[1;34mExpected: Form should be created\033[0m\n";

	try
	{
		Form validForm("valid form", 1, 150);
		std::cout << validForm;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
}

void runSecondTest()
{
	std::cout << "\n\033[34m========== Second Test ==========\033[0m\n";
	std::cout << "\033[1;34mTest: Create a form in a invalid min range for signGrade (0)\033[0m\n";
	std::cout << "\033[1;34mExpected: Form should be not be created and Grade too high exception should be thrown\033[0m\n";

	try
	{
		Form inValidForm("invalid form max", 0, 150);
		std::cout << inValidForm;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
}

void runThirdTest()
{
	std::cout << "\n\033[34m========== Third Test ==========\033[0m\n";
	std::cout << "\033[1;34mTest: Create a form in a invalid max range for signGrade (151)\033[0m\n";
	std::cout << "\033[1;34mExpected: Form should be not be created and Grade too low exception should be thrown\033[0m\n";

	try
	{
		Form inValidForm("invalid form min", 151, 150);
		std::cout << inValidForm;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
}

void runFourthTest()
{
	std::cout << "\n\033[34m========== Fourth Test ==========\033[0m\n";
	std::cout << "\033[1;34mTest: Create a form in a invalid min range for executeGrade (0)\033[0m\n";
	std::cout << "\033[1;34mExpected: Form should be not be created and Grade too high exception should be thrown\033[0m\n";

	try
	{
		Form inValidForm("invalid form max", 1, 0);
		std::cout << inValidForm;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
}

void runFifthTest()
{
	std::cout << "\n\033[34m========== Fifth Test ==========\033[0m\n";
	std::cout << "\033[1;34mTest: Create a form in a invalid max range for executeGrade (151)\033[0m\n";
	std::cout << "\033[1;34mExpected: Form should be not be created and Grade too low exception should be thrown\033[0m\n";

	try
	{
		Form inValidForm("invalid form min", 1, 151);
		std::cout << inValidForm;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
}

void runSixthTest()
{
	std::cout << "\n\033[34m========== Sixth Test ==========\033[0m\n";
	std::cout << "\033[1;34mTest: Create a valid form and let it be sign (151)\033[0m\n";
	std::cout << "\033[1;34mExpected: Form should be signed after \033[0m\n";
	Form successfulSignForm("successful signed form", 150, 150);
	Bureaucrat GodBureaucrat("GodBureaucrat", 1);
	std::cout << "\n\033[36m[pre signForm()]\033[0m\n" << successfulSignForm;
	try
	{
		GodBureaucrat.signForm(successfulSignForm);
		std::cout << "\n\033[36m[after signForm()]\033[0m\n" << successfulSignForm;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
}

void runSeventhTest()
{
	std::cout << "\n\033[34m========== Seventh Test ==========\033[0m\n";
	std::cout << "\033[1;34mTest: Create a valid form and let it be sign by a bureaucrat with lower grade than sign grade 149\033[0m\n";
	std::cout << "\033[1;34mExpected: Form should be not signed after \033[0m\n";
	Form unsuccessfulSignForm("unsuccessful signed form", 149, 149);
	Bureaucrat KarenBureaucrat("Karen", 150);
	std::cout << "\n\033[36m[pre signForm()]\033[0m\n" << unsuccessfulSignForm;
	try
	{
		KarenBureaucrat.signForm(unsuccessfulSignForm);
		std::cout << "\n\033[36m[after signForm()]\033[0m\n" << unsuccessfulSignForm;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
}

void runEighthTest()
{
	std::cout << "\n\033[34m========== Eighth Test ==========\033[0m\n";
	std::cout << "\033[1;34mTest: Create a valid form and let it be sign by a bureaucrat with equal grade both 150 \033[0m\n";
	std::cout << "\033[1;34mExpected: Form should be not signed after \033[0m\n";
	Form equalSignForm("equal signed form", 150, 150);
	Bureaucrat KarenBureaucrat("Karen", 150);
	std::cout << "\n\033[36m[pre signForm()]\033[0m\n" << equalSignForm;
	try
	{
		KarenBureaucrat.signForm(equalSignForm);
		std::cout << "\n\033[36m[after signForm()]\033[0m\n" << equalSignForm;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << "\033[33m[Exception] " << e.what() << "\033[0m\n";
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
	runSeventhTest();
	runEighthTest();
}

