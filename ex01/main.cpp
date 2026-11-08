/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmelo <bmelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:36:17 by bmelo             #+#    #+#             */
/*   Updated: 2026/11/08 19:30:57 by bmelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

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

#if FORMDEBUG == 1
    int main()
    {
    
    std::cout << "\n1.Testing Form Signing" << std::endl;
    try
    {
        Bureaucrat mbappe("Kylian", 50);
        Form formA("Form A", 75, 100);
        std::cout << formA << std::endl;
        mbappe.signForm(formA);
        std::cout << formA << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught : " << e.what() << std::endl;
    }

    std::cout << "\n2.Testing Form Signing with High Grade" << std::endl;
    try
    {
        Bureaucrat messi("Lionel", 1);
        Form formB("Form B", 75, 100);
        std::cout << formB << std::endl;
        messi.signForm(formB);
        std::cout << formB << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught : " << e.what() << std::endl;
    }

    std::cout << "\n3.Testing Form Signing with Low Grade" << std::endl;
    try
    {
        Bureaucrat ronaldo("Cristiano", 150);
        Form formC("Form C", 75, 100);
        std::cout << formC << std::endl;
        ronaldo.signForm(formC);
        std::cout << formC << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught : " << e.what() << std::endl;
    }
    
    std::cout << "\nEnd of Tests !" << std::endl;
    return (0);
    }
#endif

#if BUREAUCRATDEBUG == 0 && FORMDEBUG == 0
    int main()
    {
        std::cout << "No Debugging Enabled. Please set BUREAUCRATDEBUG or FORMDEBUG to 1 in the Makefile to run tests." << std::endl;
        return (0);
    }
#endif