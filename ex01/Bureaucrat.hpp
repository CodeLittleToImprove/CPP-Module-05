/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:25:34 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/07/29 16:25:35 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

#include "Form.hpp"

class Form;
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
		const std::string& getBureaucratName() const;
		unsigned int	getGrade() const;
		void	setGrade(int grade);
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form& form);
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