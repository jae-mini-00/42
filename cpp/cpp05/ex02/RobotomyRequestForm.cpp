#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 25, 5), target("default")
{
    std::cout   << "RobotomyRequestForm default constructor called"  << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 25, 5), target(target)
{
    std::cout   << "RobotomyRequestForm constructor called"  << std::endl;    
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), target(other.target)
{
    std::cout   << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout   << "RobotomyRequestForm copy assignment operator called" << std::endl;
    if (this != &other)
    {
        std::cout   << "Can't copy assignment name" << std::endl;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw (AForm::FormNotSigned(executor.getName()));
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException(this->getName());
    std::cout   << "Starts making drilling noises." << std::endl;
    
    std::srand(std::time(NULL));
    int random_number = std::rand(); 
    if (random_number % 2)
        std::cout   << "[Success] The robotomy of " << target << " was completed successfully." << std::endl;
    else
        std::cout   << "[Failure] The robotomy of " << target << " has failed." << std::endl;
}