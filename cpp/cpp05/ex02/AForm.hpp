#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private :
        const std::string name;
        bool IsSigned;
        const int GradeToSign;
        const int GradeToExecute;

        AForm& operator=(const AForm& other);
    public :
        // 예외 처리 객체
        class GradeTooLowException : public std::exception
        {
            private :
                std::string name;
            public :
                GradeTooLowException (std::string name) throw() : name(name) {};
                virtual ~GradeTooLowException() throw() {}

                virtual const char* what() const throw()
                {
                    std::cerr   << name << " ";
                    return ("Grade too low");
                }
        };
        class GradeTooHighException : public std::exception
        {
            private :
                std::string name;
            public :
                GradeTooHighException (std::string name) throw() : name(name) {};
                virtual ~GradeTooHighException() throw() {}

            public :
                virtual const char* what() const throw()
                {
                    std::cerr   << name << " ";
                    return ("Grade too high");
                }
        };
        // 생서자, 대입 연산자 및 소멸자
        AForm();
        AForm(const std::string& name, int GradeToSign, int GradeToExecute) throw (AForm::GradeTooHighException, AForm::GradeTooLowException);
        AForm(const AForm& other);
        virtual ~AForm();
        // 매서드
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& bureaucrat) throw (AForm::GradeTooLowException);
        // virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm &data);

#endif