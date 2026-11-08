/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmelo <bmelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 19:29:43 by bmelo             #+#    #+#             */
/*   Updated: 2026/11/08 19:29:43 by bmelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>


#if BUREAUCRATDEBUG == 1
    int main()
    {
    std::cout << "1.Test Normal Construction and Stream Operator :" << std::endl;
    try
    {
        Bureaucrat joe("Joe", 75);
        std::cout << joe << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught : " << e.what() << std::endl;
    }
    
    std::cout << "\n2.Test Upgrading And Downgrading" << std::endl;
    try
    {
        Bureaucrat rania("Rania", 2);
        std::cout << rania << std::endl;

        rania.upGrade();
        std::cout << "Promotion : " << rania << std::endl;
        rania.downGrade();
        std::cout << "Regression : " << rania << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught : " << e.what() << std::endl;
    }

    std::cout << "\n3.Testing Construction Exceptions (Too High)" << std::endl;
    try
    {
        std::cout << "Trying to create a too high grade Burreaucrat" << std::endl;
        Bureaucrat bryan("Bryan", 0);
        std::cout << bryan << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught successfully: " <<e.what() << std::endl;
    }

    std::cout << "\n4.Testing Construction Exceptions (Too Low)" << std::endl;
    try
    {
        std::cout << "Trying to create a too high grade Burreaucrat" << std::endl;
        Bureaucrat merdien("Merdien", 153);
        std::cout << merdien << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught successfully: " <<e.what() << std::endl;
    }

    std::cout << "\n5.Testing Runtime Upgrade Exception (Above 1)" << std::endl;
    try
    {
        Bureaucrat batman("Bruce Wayne", 1);
        std::cout << batman << std::endl;
        std::cout << "Attempting to upgrade grade 1 ..." << std::endl;
        batman.upGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught successfully : " << e.what() << std::endl;
    }

    std::cout << "\n6.Testing Runtime Downgrade Exception (Below 150)" << std::endl;
    try
    {
        Bureaucrat robin("Robin", 150);
        std::cout << robin << std::endl;
        std::cout << "Attempting to downgrade grade 150 ..." << std::endl;
        robin.downGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught successfully : " << e.what() << std::endl;
    }

    std::cout << "\nEnd of Tests !" << std::endl;
    return (0);
    }
#endif

#if SHRUBBERYCREATIONFORMDEBUG == 1
    int main()
    {
        std::cout << "Testing ShrubberyCreationForm Execution" << std::endl;
        try
        {
            Bureaucrat alice("Alice", 1);
            ShrubberyCreationForm shrubberyForm("garden");
            std::cout << shrubberyForm << std::endl;

            alice.signForm(shrubberyForm);
            std::cout << shrubberyForm << std::endl;

            alice.execute(shrubberyForm);
            if (shrubberyForm.getIsSigned() == true && shrubberyForm.getGradeToExecute() >= alice.getGrade())
                std::cout << "Shrubbery request executed successfully!" << std::endl;
            else
                std::cout << "Shrubbery request failed ..." << std::endl;

        }
        catch (std::exception &e)
        {
            std::cerr << "Exception caught : " << e.what() << std::endl;
        }

        return (0);
    }
#endif

#if PRESIDENTIALPARDONFORMDEBUG == 1
    int main()
    {
        std::cout << "Testing PresidentialPardonForm Execution" << std::endl;
        try
        {
            Bureaucrat bob("Bob", 6);
            PresidentialPardonForm pardonForm("Charlie");
            std::cout << pardonForm << std::endl;

            bob.signForm(pardonForm);
            std::cout << pardonForm << std::endl;

            bob.execute(pardonForm);
            if (pardonForm.getIsSigned() == true && pardonForm.getGradeToExecute() >= bob.getGrade())
                std::cout << "Presidential pardon executed successfully!" << std::endl;
            else
                std::cout << "Presidential pardon failed ..." << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception caught : " << e.what() << std::endl;
        }

        return (0);
    }
#endif

#if ROBOTOMYREQUESTFORMDEBUG == 1
    int main()
    {
        std::srand(std::time(NULL));
        std::cout << "Testing RobotomyRequestForm Execution" << std::endl;
        try
        {
            Bureaucrat dave("Dave", 12);
            RobotomyRequestForm robotomyForm("Eve");
            std::cout << robotomyForm << std::endl;

            dave.signForm(robotomyForm);
            std::cout << robotomyForm << std::endl;

            dave.execute(robotomyForm);
            if (robotomyForm.getIsSigned() == true && robotomyForm.getGradeToExecute() >= dave.getGrade())
                std::cout << "Robotomy request executed successfully!" << std::endl;
            else
                std::cout << "Robotomy request failed ..." << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception caught : " << e.what() << std::endl;
        }

        return (0);
    }
#endif

#if BUREAUCRATDEBUG == 0 && SHRUBBERYCREATIONFORMDEBUG == 0 && PRESIDENTIALPARDONFORMDEBUG == 0 && ROBOTOMYREQUESTFORMDEBUG == 0
    int main()
    {
        std::cout << "No Debugging Enabled. Please set BUREAUCRATDEBUG or SHRUBBERYCREATIONFORMDEBUG or PRESIDENTIALPARDONFORMDEBUG or ROBOTOMYREQUESTFORMDEBUG to 1 in the Makefile to run tests." << std::endl;
        return (0);
    }
#endif