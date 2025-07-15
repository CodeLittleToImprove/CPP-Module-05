/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:58:29 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/07/15 19:58:32 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const unsigned int	_signGrade;
		const unsigned int	_executeGrade;
		bool				_isSigned;
	public:
		AForm();
		AForm(const std::string &name, unsigned int signGrade, unsigned int executeGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
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
		class FormNotSignedException: public std::exception
		{
		public:
			const char *what() const throw();
		};
};
std::ostream& operator<<(std::ostream& os, const AForm& a);