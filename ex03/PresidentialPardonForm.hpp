/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmelo <bmelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 22:00:03 by bmelo             #+#    #+#             */
/*   Updated: 2026/11/06 22:00:03 by bmelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

#ifndef PRESIDENTIALPARDONFORMDEBUG
#define PRESIDENTIALPARDONFORMDEBUG 0
#endif

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        virtual ~PresidentialPardonForm();

        void execute(const Bureaucrat &executor) const;
        static AForm* create(const std::string &target);
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form);

#endif