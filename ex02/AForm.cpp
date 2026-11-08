/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmelo <bmelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 19:29:35 by bmelo             #+#    #+#             */
/*   Updated: 2026/11/08 19:29:35 by bmelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(75), gradeToExecute(45) 
{}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

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

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
    {
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