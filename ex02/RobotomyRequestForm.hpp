#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

#ifndef ROBOTDEBUG
#define ROBOTDEBUG 0
#endif

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        virtual ~RobotomyRequestForm();

        void setTarget(const std::string &target);
        std::string getTarget() const;
        virtual RobotomyRequestForm *clone() const;
        virtual void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form);

#endif