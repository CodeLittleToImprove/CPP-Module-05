/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:33:10 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/07/29 16:33:11 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		unsigned int	getSignGrade() const;
		unsigned int	getExecuteGrade() const;
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