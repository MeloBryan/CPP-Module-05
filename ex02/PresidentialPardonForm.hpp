#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

#ifndef PRESIDENTDEBUG
#define PRESIDENTDEBUG 0
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
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form);

#endif