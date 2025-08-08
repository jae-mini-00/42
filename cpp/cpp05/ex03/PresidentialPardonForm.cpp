#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), target("default")
{
    std::cout   << "PresidentialPardonForm default constructor called"  << std::endl;    
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout   << "PresidentialPardonForm constructor called"  << std::endl;    
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), target(other.target)
{
    std::cout   << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw (AForm::FormNotSigned(executor.getName()));
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException(this->getName());
    
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}