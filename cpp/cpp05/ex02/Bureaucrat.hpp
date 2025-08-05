#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private :
        const std::string name;
        int grade;

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
        // 생성자 소멸자
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade) throw(GradeTooHighException, GradeTooLowException);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        // 매서드
        std::string getName() const;
        int getGrade() const;
        void IncrementGrade() throw(GradeTooHighException);
        void DecrementGrade() throw(GradeTooLowException);
        void signForm(AForm& form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &data);

#endif