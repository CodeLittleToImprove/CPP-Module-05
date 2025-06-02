#pragma once

# include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int			_grade;
	public:
		Bureaucrat();
		explicit Bureaucrat(int grade);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		std::string getName() const;
		int	getGrade() const;
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
		virtual std::string getClassName() const;
};
std::ostream &operator<<(std::ostream &os, Bureaucrat &a);