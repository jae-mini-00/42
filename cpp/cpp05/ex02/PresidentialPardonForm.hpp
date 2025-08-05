#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private :
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    
    public :
        // 생서자, 대입 연산자 및 소멸자
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();
        // 매서드
        void execute(Bureaucrat const & executor) const;
};

#endif