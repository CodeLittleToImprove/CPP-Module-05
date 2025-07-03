#pragma once

# include <iostream>

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		const unsigned int	_signGrade;
		const unsigned int	_executeGrade;
		bool				_isSigned;
	public:
		Form();
		Form(const std::string &name, int unsigned signGrade, unsigned executeGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		const std::string	getName() const;
		unsigned int		getSignGrade() const;
		unsigned int		getExecuteGrade() const;
		bool				getIsSigned() const;
		void				setSigner(Bureaucrat &signer);
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
		// virtual std::string getClassName() const;
};
std::ostream &operator<<(std::ostream &os, Form &a);