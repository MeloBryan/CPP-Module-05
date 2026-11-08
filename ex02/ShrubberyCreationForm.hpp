/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmelo <bmelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 19:30:31 by bmelo             #+#    #+#             */
/*   Updated: 2026/11/08 19:30:31 by bmelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

#ifndef SHRUBBERYCREATIONFORMDEBUG
#define SHRUBBERYCREATIONFORMDEBUG 0
#endif

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        virtual ~ShrubberyCreationForm();

        void setTarget(const std::string &target);
        std::string getTarget() const;
        void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form);

#endif