#pragma once

# include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int			_grade;
	public:
		Bureaucrat();
		explicit Bureaucrat(int grade);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		const std::string& getName() const;
		unsigned int	getGrade() const;
		void	setGrade(int grade);
		void	incrementGrade();
		void	decrementGrade();
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
std::ostream& operator<<(std::ostream& os, Bureaucrat& a);