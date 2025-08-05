#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private :
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    
    public :
        // 생서자, 대입 연산자 및 소멸자
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
        // 매서드
        void execute(Bureaucrat const & executor) const;
};

#endif