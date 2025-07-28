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

#include <cstdlib>  // for std::rand, std::srand
#include <ctime>    // for std::time
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string _target;

public:
	RobotomyRequestForm();
	explicit RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();
	const std::string& getTarget() const;
	void executeAction() const;
};
