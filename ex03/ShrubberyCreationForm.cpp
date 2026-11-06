/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmelo <bmelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 22:00:11 by bmelo             #+#    #+#             */
/*   Updated: 2026/11/06 22:00:11 by bmelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <ostream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default_target")
{
}

void ShrubberyCreationForm::setTarget(const std::string &target)
{
    this->target = target;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (this->target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!this->getIsSigned())
    {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute())
    {
        throw AForm::GradeTooLowException();
    }

    std::string filename = this->getTarget() + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if (outfile.is_open())
    {
        outfile << "      /\\      " << std::endl;
        outfile << "     /\\*\\     " << std::endl;
        outfile << "    /\\O\\*\\    " << std::endl;
        outfile << "   /*/\\/\\/\\   " << std::endl;
        outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
        outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
        outfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
        outfile << "      ||      " << std::endl;
        outfile << "      ||      " << std::endl;
        outfile.close();
    }
    else
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
    }
}

AForm* ShrubberyCreationForm::create(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
    out << "ShrubberyCreationForm: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute() << ", Target: " << form.getTarget();
    return out;
}