/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:58:40 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/07/15 19:58:41 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

#include "AForm.hpp"

class AForm;
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
		void	signForm(AForm& a);
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