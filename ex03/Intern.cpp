/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmelo <bmelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 21:02:25 by bmelo             #+#    #+#             */
/*   Updated: 2026/11/08 21:30:48 by bmelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{}

Intern::~Intern()
{}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    struct FormMapping
    {
        std::string name;
        AForm* (*create)(const std::string&);
    };

    static const FormMapping forms[] = 
    {
        {"shrubbery creation", &ShrubberyCreationForm::create},
        {"robotomy request", &RobotomyRequestForm::create},
        {"presidential pardon", &PresidentialPardonForm::create}
    };
    for (int i=0;i<3;i++)
    {
        if (forms[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (forms[i].create(target));
        }
    }

    std::cerr << "Intern cannot create form : " << formName << std::endl;
    return (NULL);
}
