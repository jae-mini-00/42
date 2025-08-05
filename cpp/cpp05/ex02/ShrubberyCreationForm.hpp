#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private :
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    
    public :
        // 생서자, 대입 연산자 및 소멸자
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
        // 매서드
        void execute(Bureaucrat const & executor) const;
};

#endif