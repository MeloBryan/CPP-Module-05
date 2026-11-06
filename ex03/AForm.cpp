/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmelo <bmelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 21:59:43 by bmelo             #+#    #+#             */
/*   Updated: 2026/11/06 21:59:43 by bmelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include <ostream>

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(75), gradeToExecute(45) 
{}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) 
{}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

AForm &AForm::operator=(const AForm &other) 
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm()
{}

std::string AForm::getName() const
{
    return (name);
}

bool AForm::getIsSigned() const
{
    return (isSigned);
}

int AForm::getGradeToSign() const
{
    return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (gradeToExecute);
}

void AForm::beSigned(int grade)
{
    if (grade < gradeToSign) {
        throw GradeTooLowException();
    }
    this->isSigned = true;
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed!");
}

AForm::FormNotSignedException::~FormNotSignedException() throw()
{}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form " << form.getName() << " ,signed : " << (form.getIsSigned() ? "yes" : "no")
        << ", grade required to sign: " << form.getGradeToSign()
        << ", grade required to execute: " << form.getGradeToExecute();
    return (out); 
}