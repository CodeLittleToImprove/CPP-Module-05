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


// void printHeader(const std::string& title, const std::string& description, const std::string& expected)
// {
// 	std::cout << "\n\033[34m========== " << title << " ==========\033[0m\n";
// 	std::cout << "\033[1;34mTest: " << description << "\033[0m\n";
// 	std::cout << "\033[1;34mExpected: " << expected << "\033[0m\n";
// }
//

// }
//
// /* Test 2: Invalid min range for signGrade */
// void runSecondTest()
// {
// 	printHeader(
// 		"Second Test",
// 		"Create a form with signGrade = 0 (invalid min)",
// 		"Form should NOT be created and GradeTooHighException thrown"
// 	);
//
// 	try
// 	{
// 		AAForm invalidForm("invalid form min signGrade", 0, 150);
// 		std::cout << invalidForm;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		printException(e);
// 	}
// }
//
// /* Test 3: Invalid max range for signGrade */
// void runThirdTest()
// {
// 	printHeader(
// 		"Third Test",
// 		"Create a form with signGrade = 151 (invalid max)",
// 		"Form should NOT be created and GradeTooLowException thrown"
// 	);
//
// 	try
// 	{
// 		AAForm invalidForm("invalid form max signGrade", 151, 150);
// 		std::cout << invalidForm;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		printException(e);
// 	}
// }
//
// /* Test 4: Invalid min range for executeGrade */
// void runFourthTest()
// {
// 	printHeader(
// 		"Fourth Test",
// 		"Create a form with executeGrade = 0 (invalid min)",
// 		"Form should NOT be created and GradeTooHighException thrown"
// 	);
//
// 	try
// 	{
// 		AAForm invalidForm("invalid form min executeGrade", 1, 0);
// 		std::cout << invalidForm;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		printException(e);
// 	}
// }
//
// /* Test 5: Invalid max range for executeGrade */
// void runFifthTest()
// {
// 	printHeader(
// 		"Fifth Test",
// 		"Create a form with executeGrade = 151 (invalid max)",
// 		"Form should NOT be created and GradeTooLowException thrown"
// 	);
//
// 	try
// 	{
// 		AAForm invalidForm("invalid form max executeGrade", 1, 151);
// 		std::cout << invalidForm;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		printException(e);
// 	}
// }
//
// /* Test 6: Successful signing (bureaucrat grade 1) */
// void runSixthTest()
// {
// 	printHeader(
// 			"Sixth Test",
// 			"Create a valid form and sign it (signGrade: 150, bureaucrat grade: 1)",
// 			"Form should be signed"
// 		);
//
// 	AAForm successfulSignForm("successful signed form", 150, 150);
// 	Bureaucrat godBureaucrat("GodBureaucrat", 1);
// 	std::cout << godBureaucrat << std::endl;
// 	std::cout << "\n\033[36m[pre signForm()]\033[0m\n" << successfulSignForm;
// 	try
// 	{
// 		godBureaucrat.signForm(successfulSignForm);
// 		std::cout << "\n\033[36m[after signForm()]\033[0m\n" << successfulSignForm;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		printException(e);
// 	}
// }
//
// /* Test 7: Unsuccessful signing (bureaucrat grade too low) */
// void runSeventhTest()
// {
// 	printHeader(
// 			"Seventh Test",
// 			"Create a valid form and attempt sign by low-grade bureaucrat (signGrade: 149, bureaucrat grade: 150)",
// 			"Form should NOT be signed"
// 		);
//
// 	AAForm unsuccessfulSignForm("unsuccessful signed form", 149, 149);
// 	Bureaucrat karenBureaucrat("Super Karen", 150);
// 	std::cout << karenBureaucrat << std::endl;
// 	std::cout << "\n\033[36m[pre signForm()]\033[0m\n" << unsuccessfulSignForm;
// 	try
// 	{
// 		karenBureaucrat.signForm(unsuccessfulSignForm);
// 		std::cout << "\n\033[36m[after signForm()]\033[0m\n" << unsuccessfulSignForm;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cout << " i should catch it here?" << std::endl;
// 		printException(e);
// 	}
// }
//
// /* Test 8: Successful signing with equal grade */
// void runEighthTest()
// {
// 	printHeader(
// 			"Eighth Test",
// 			"Create a valid form and sign by bureaucrat with grade equal to signGrade (both 150)",
// 			"Form should be signed"
// 		);
//
// 	AAForm equalSignForm("equal signed form", 150, 150);
// 	Bureaucrat nonKarenBureaucrat("NonKaren", 150);
// 	std::cout << nonKarenBureaucrat << std::endl;
// 	std::cout << "\n\033[36m[pre signForm()]\033[0m\n" << equalSignForm;
// 	try
// 	{
// 		nonKarenBureaucrat.signForm(equalSignForm);
// 		std::cout << "\n\033[36m[after signForm()]\033[0m\n" << equalSignForm;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		printException(e);
// 	}
// }
//
// /* Test 9: Unsuccessful signing (bureaucrat grade too low for high signGrade) */
// void runNinthTest()
// {
// 	printHeader(
// 		"Ninth Test",
// 		"Create a valid form (signGrade: 1) and attempt sign by bureaucrat grade 150",
// 		"Form should NOT be signed"
// 	);
// 	AAForm highGradeSignForm("High signed form", 1, 1);
// 	Bureaucrat nonKarenBureaucrat("NonKaren", 150);
// 	std::cout << nonKarenBureaucrat << std::endl;
// 	std::cout << "\n\033[36m[pre signForm()]\033[0m\n" << highGradeSignForm;
// 	try
// 	{
// 		nonKarenBureaucrat.signForm(highGradeSignForm);
// 		std::cout << "\n\033[36m[after signForm()]\033[0m\n" << highGradeSignForm;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		printException(e);
// 	}
// }

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

void runPresidentialPardonFormTest1()
{
	printHeader
	(
		"First Test",
		"Create a Presidental-pardonform and sign it by a valid bureaucrat ",
		"Form should be created and executed"
	);

	Bureaucrat TopBureaucrat("TopBureaucrat", 1);


	PresidentialPardonForm presidential("Name 1");
	PresidentialPardonForm presidential2("Name 2");
	try
	{
		presidential.beSigned(TopBureaucrat);				// Success with TopBureaucrat
		presidential.execute(TopBureaucrat);				// Success with TopBureaucrat
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

void runPresidentialPardonFormTest2()
{
	printHeader
	(
	"Second Test",
	"Test: Try to execute an unsigned PresidentialPardonForm",
	"Exception should be thrown for unsigned form"
	);
	Bureaucrat TopBureaucrat("TopBureaucrat", 1);
	PresidentialPardonForm presidential("Target");

	try
	{
		presidential.execute(TopBureaucrat); // should throw because not signed
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

void runPresidentialPardonFormTest3()
{
	printHeader
	(
	"Third Test",
	"Bureaucrat with low grade tries to sign the form",
	"GradeTooLowException should be thrown"
	);

	Bureaucrat lowBureaucrat("Intern", 150);
	PresidentialPardonForm presidential("Target");

	try
	{
		presidential.beSigned(lowBureaucrat);
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

void runPresidentialPardonFormTest4()
{
	printHeader(
		"Fourth Test",
		"Bureaucrat with low grade tries to execute signed form",
		"GradeTooLowException should be thrown"
	);

	Bureaucrat topBureaucrat("Boss", 1);
	Bureaucrat lowBureaucrat("Intern", 150);
	PresidentialPardonForm presidential("Target");

	try
	{
		presidential.beSigned(topBureaucrat);
		presidential.execute(lowBureaucrat); // should fail
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

void runPresidentialPardonFormTest5()
{
	printHeader(
		"Fifth Test",
		"Copy a signed form and execute the copy",
		"Both original and copy can be executed"
	);

	Bureaucrat boss("Boss", 1);
	PresidentialPardonForm original("Target");

	try
	{
		original.beSigned(boss);
		PresidentialPardonForm copy(original);

		original.execute(boss);
		copy.execute(boss);
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

void runRobotomyTest()
{
	std::srand(std::time(NULL));  // seed with current time
	printHeader(
		"Robotomy Test (Randomized)",
		"Run RobotomyRequestForm execute 10 times to observe random outcomes",
		"Roughly 50% should succeed, 50% should fail (output may vary)"
	);

	Bureaucrat executor("TopExecutor", 1);
	RobotomyRequestForm form("RandomTarget");

	try
	{
		form.beSigned(executor);

		for (int i = 0; i < 10; ++i)
		{
			std::cout << "Attempt #" << i + 1 << ": ";
			form.execute(executor);
		}
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

void runShrubberyTest1()
{
	printHeader(
		"Shrubbery Test 1",
		"Execute signed ShrubberyCreationForm with high-grade Bureaucrat",
		"Should create a file with a tree inside"
	);

	Bureaucrat top("TopBureaucrat", 1);
	ShrubberyCreationForm form("Garden");

	try
	{
		form.beSigned(top);
		form.execute(top);
		std::cout << "\033[32mSuccess: File 'Garden_shrubbery' should now exist.\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		printException(e);
	}
}

int main(void)
{
	// runPresidentialPardonFormTest1();
	// runPresidentialPardonFormTest2();
	// runPresidentialPardonFormTest3();
	// runPresidentialPardonFormTest4();
	// runPresidentialPardonFormTest5();
	// runRobotomyTest();
	runShrubberyTest1();
	// std::cout << "Constructors" << std::endl;




	// std::cout << "Presidential Pardon Test 1" << std::endl;
	// try
	// {
	//
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << std::endl;

	// std::cout << "Presidential Pardon Test 2" << std::endl;
	// TopBureaucrat.signForm(presidential2);				// Success with TopBureaucrat
	// TopBureaucrat.executeForm(presidential2);			// Success with TopBureaucrat
	// std::cout << std::endl;
	// runFirstTest();
	// runSecondTest();
	// runThirdTest();
	// runFourthTest();
	// runFifthTest();
	// runSixthTest();
	// runSeventhTest();
	// runEighthTest();
	// runNinthTest();
}

