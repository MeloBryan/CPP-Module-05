#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

Bureaucrat::Bureaucrat() : name("Default"), grade(75) 
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) 
{
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) 
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) 
{
    if (this != &other) {
        name = other.name;
        grade = other.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() 
{}

std::string Bureaucrat::getName() const 
{
    return (this->name);
}

int Bureaucrat::getGrade() const 
{
    return (this->grade);
}

void Bureaucrat::upGrade() 
{
    if (grade <= 1) {
        throw GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::downGrade() 
{
    if (grade >= 150) {
        throw GradeTooLowException();
    }
    this->grade++;
}

void Bureaucrat::execute(const AForm &form) const 
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executes " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << this->name << " cannot execute " << form.getName() << " because: " << e.what() << std::endl;
    }
}

void Bureaucrat::signForm(AForm &form) const 
{
    try
    {
        form.beSigned(this->grade);
        std::cout << this->name << " signs " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << this->name << " cannot sign " << form.getName() << " because: " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) 
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}