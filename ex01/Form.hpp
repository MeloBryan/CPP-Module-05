#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <exception>

#ifndef FORMDEBUG
#define FORMDEBUG 0
#endif

class Bureaucrat;

class Form
{
    private :
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public :
        Form();
        Form(std::string const name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form &operator=(const Form &copy);
        ~Form();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat const &bureaucrat);
        void checkGrade(int grade) const;
        
        class GradeTooHighException : public std::exception
        {
            public :
                virtual ~GradeTooHighException() throw() {}
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public :
                virtual ~GradeTooLowException() throw() {}
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif