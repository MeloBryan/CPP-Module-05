#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

#ifndef BUREAUCRATDEBUG
    #define BUREAUCRATDEBUG 0
#endif

class Form;

class Bureaucrat
{
    private :
        const std::string name;
        int grade;

    public :
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        std::string getName(void) const;
        int getGrade(void) const;

        void upGrade(void);
        void downGrade(void);
        void signForm(Form &form);

        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif