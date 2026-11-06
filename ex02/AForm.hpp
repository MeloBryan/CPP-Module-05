#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

#ifndef AFORMDEBUG
#define AFORMDEBUG 0
#endif

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public :
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(int grade);
        virtual void execute(const Bureaucrat &executor) const = 0;
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
                virtual ~FormNotSignedException() throw();
        };

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
                virtual ~GradeTooHighException() throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
                virtual ~GradeTooLowException() throw();
        };
};

#endif