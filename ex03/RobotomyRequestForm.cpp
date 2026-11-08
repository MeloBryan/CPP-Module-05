/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmelo <bmelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 22:00:07 by bmelo             #+#    #+#             */
/*   Updated: 2026/11/06 22:00:07 by bmelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <ostream>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return (*this);
}

RobotomyRequestForm *RobotomyRequestForm::clone() const
{
    return (new RobotomyRequestForm(*this));
}

void RobotomyRequestForm::setTarget(const std::string &target)
{
    this->target = target;
}

std::string RobotomyRequestForm::getTarget() const
{
    return (this->target);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Bzzzz... Bzzzz... " << std::endl;
    if (std::rand() % 2)
        std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << this->getTarget() << "." << std::endl;
}

AForm* RobotomyRequestForm::create(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form)
{
    out << "Form Name: " << form.getName() << std::endl;
    out << "Target: " << form.getTarget() << std::endl;
    out << "Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
    out << "Grade Required to Sign: " << form.getGradeToSign() << std::endl;
    out << "Grade Required to Execute: " << form.getGradeToExecute() << std::endl;
    return (out);
}