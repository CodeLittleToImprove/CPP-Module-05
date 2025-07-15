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

/* Test 1: Valid form creation */
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
	catch (const std::exception& e)
	{
		printException(e);
	}
}

/* Test 2: Invalid min range for signGrade */
void runSecondTest()
{
	printHeader(
		"Second Test",
		"Create a form with signGrade = 0 (invalid min)",
		"Form should NOT be created and GradeTooHighException thrown"
	);

	try
	{
		Form invalidForm("invalid form min signGrade", 0, 150);
		std::cout << invalidForm;
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

/* Test 3: Invalid max range for signGrade */
void runThirdTest()
{
	printHeader(
		"Third Test",
		"Create a form with signGrade = 151 (invalid max)",
		"Form should NOT be created and GradeTooLowException thrown"
	);

	try
	{
		Form invalidForm("invalid form max signGrade", 151, 150);
		std::cout << invalidForm;
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

/* Test 4: Invalid min range for executeGrade */
void runFourthTest()
{
	printHeader(
		"Fourth Test",
		"Create a form with executeGrade = 0 (invalid min)",
		"Form should NOT be created and GradeTooHighException thrown"
	);

	try
	{
		Form invalidForm("invalid form min executeGrade", 1, 0);
		std::cout << invalidForm;
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

/* Test 5: Invalid max range for executeGrade */
void runFifthTest()
{
	printHeader(
		"Fifth Test",
		"Create a form with executeGrade = 151 (invalid max)",
		"Form should NOT be created and GradeTooLowException thrown"
	);

	try
	{
		Form invalidForm("invalid form max executeGrade", 1, 151);
		std::cout << invalidForm;
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

/* Test 6: Successful signing (bureaucrat grade 1) */
void runSixthTest()
{
	printHeader(
			"Sixth Test",
			"Create a valid form and sign it (signGrade: 150, bureaucrat grade: 1)",
			"Form should be signed"
		);

	Form successfulSignForm("successful signed form", 150, 150);
	Bureaucrat godBureaucrat("GodBureaucrat", 1);
	std::cout << godBureaucrat << std::endl;
	std::cout << "\n\033[36m[pre signForm()]\033[0m\n" << successfulSignForm;
	try
	{
		godBureaucrat.signForm(successfulSignForm);
		std::cout << "\n\033[36m[after signForm()]\033[0m\n" << successfulSignForm;
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

/* Test 7: Unsuccessful signing (bureaucrat grade too low) */
void runSeventhTest()
{
	printHeader(
			"Seventh Test",
			"Create a valid form and attempt sign by low-grade bureaucrat (signGrade: 149, bureaucrat grade: 150)",
			"Form should NOT be signed"
		);

	Form unsuccessfulSignForm("unsuccessful signed form", 149, 149);
	Bureaucrat karenBureaucrat("Super Karen", 150);
	std::cout << karenBureaucrat << std::endl;
	std::cout << "\n\033[36m[pre signForm()]\033[0m\n" << unsuccessfulSignForm;
	try
	{
		karenBureaucrat.signForm(unsuccessfulSignForm);
		std::cout << "\n\033[36m[after signForm()]\033[0m\n" << unsuccessfulSignForm;
	}
	catch (const std::exception& e)
	{
		std::cout << " i should catch it here?" << std::endl;
		printException(e);
	}
}

/* Test 8: Successful signing with equal grade */
void runEighthTest()
{
	printHeader(
			"Eighth Test",
			"Create a valid form and sign by bureaucrat with grade equal to signGrade (both 150)",
			"Form should be signed"
		);

	Form equalSignForm("equal signed form", 150, 150);
	Bureaucrat nonKarenBureaucrat("NonKaren", 150);
	std::cout << nonKarenBureaucrat << std::endl;
	std::cout << "\n\033[36m[pre signForm()]\033[0m\n" << equalSignForm;
	try
	{
		nonKarenBureaucrat.signForm(equalSignForm);
		std::cout << "\n\033[36m[after signForm()]\033[0m\n" << equalSignForm;
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

/* Test 9: Unsuccessful signing (bureaucrat grade too low for high signGrade) */
void runNinthTest()
{
	printHeader(
		"Ninth Test",
		"Create a valid form (signGrade: 1) and attempt sign by bureaucrat grade 150",
		"Form should NOT be signed"
	);
	Form highGradeSignForm("High signed form", 1, 1);
	Bureaucrat nonKarenBureaucrat("NonKaren", 150);
	std::cout << nonKarenBureaucrat << std::endl;
	std::cout << "\n\033[36m[pre signForm()]\033[0m\n" << highGradeSignForm;
	try
	{
		nonKarenBureaucrat.signForm(highGradeSignForm);
		std::cout << "\n\033[36m[after signForm()]\033[0m\n" << highGradeSignForm;
	}
	catch (const std::exception& e)
	{
		printException(e);
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
	runNinthTest();
}

