#pragma once

# include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const unsigned int	_signGrade;
		const unsigned int	_executeGrade;
		bool				_isSigned;
	public:
		Form();
		Form(const std::string &name, unsigned int signGrade, unsigned int executeGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		const std::string&	getName() const;
		const unsigned int	getSignGrade() const;
		const unsigned int	getExecuteGrade() const;
		bool				getIsSigned() const;
		void				beSigned(Bureaucrat& signer);
		//exceptions
		class GradeTooLowException : public std::exception
		{
		public:
			const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
		public:
			const char *what() const throw();
		};
};
std::ostream& operator<<(std::ostream& os, const Form& a);