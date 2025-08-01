/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:49:09 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/07/15 19:49:18 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string _target;

public:
	ShrubberyCreationForm();
	explicit ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
	const std::string& getTarget() const;
	void executeAction() const;
	class FailInFileException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};
