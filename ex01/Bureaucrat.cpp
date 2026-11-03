/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:48:42 by bmelo             #+#    #+#             */
/*   Updated: 2026/11/03 22:55:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <ostream>

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
    std::cout << "DefaultBureaucrat created." << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
    std::cout << "Ohhh there is " << name << " right here !" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
    std::cout << "Copy constructor called for " << this->name << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout << "Assignement operator called" << std::endl;
    if (this != &copy)
    {
        this->grade = copy.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << this->name << " is fired !" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::upGrade(void)
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::downGrade(void)
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high !!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low !!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}