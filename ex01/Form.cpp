
#include "Form.hpp"
#include <iostream>
#include <ostream>

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
    std::cout << "DefaultForm created." << std::endl;
}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "Form created." << std::endl;
    checkGrade(gradeToSign);
    checkGrade(gradeToExecute);
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Form Copy constructor called for " << this->name << std::endl;
}

Form &Form::operator=(const Form &copy)
{
    std::cout << "Form Assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->isSigned = copy.isSigned;
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Form " << this->name << " is destroyed !" << std::endl;
}

std::string Form::getName() const
{
    return (this->name);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    this->isSigned = true;
}

int Form::getGradeToSign() const
{
    return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

void Form::checkGrade(int grade) const
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high !");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low !");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << ", form grade " << form.getGradeToSign() << ", is signed: " << (form.getIsSigned() ? "true" : "false");
    return (out);
}