#include "AForm.hpp"

AForm::AForm() : name("NoName"), IsSigned(false), GradeToSign(150), GradeToExecute(150)
{ std::cout   << "AForm default constructor called"  << std::endl; }

AForm::AForm(const std::string& name, int GradeToSign, int GradeToExecute) throw (AForm::GradeTooHighException, AForm::GradeTooLowException)
: name(name), IsSigned(false), GradeToSign(GradeToSign), GradeToExecute(GradeToExecute)
{
    std::cout   << "AForm constructor called" << std::endl;
    if (GradeToSign > 150 || GradeToExecute > 150 || GradeToSign > 150)
        throw AForm::GradeTooLowException(name);
    if (GradeToSign < 1 || GradeToExecute < 1 || GradeToSign < 1)
        throw AForm::GradeTooHighException(name); 
        
}

AForm::AForm(const AForm& other)
: name(other.name), IsSigned(other.IsSigned), GradeToSign(other.GradeToSign), GradeToExecute(other.GradeToExecute)
{ std::cout   << "AForm copy constructor called" << std::endl; }

AForm::~AForm()
{ std::cout << "AForm destructor called" << std::endl; }

AForm& AForm::operator=(const AForm& other) 
{
    std::cout   << "AForm copy assignment operator called" << std::endl;
    if (this != &other)
    {
        std::cout   << "Can't copy assignment name" << std::endl;
    }
    return *this;
}

std::string AForm::getName() const { return (this->name); }

bool AForm::getIsSigned() const { return (this->IsSigned); }

int AForm::getGradeToSign() const { return (this->GradeToSign); }

int AForm::getGradeToExecute() const { return (this->GradeToExecute); }

void AForm::beSigned(const Bureaucrat& bureaucrat) throw (AForm::GradeTooLowException)
{
    if (bureaucrat.getGrade() > GradeToSign)
        throw (AForm::GradeTooLowException(bureaucrat.getName()));
    IsSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm &data)
{
    os  << "AForm name: " << data.getName() << ", AForm IsSined: " << data.getIsSigned()
        << ", AForm GradeToSign: " << data.getGradeToSign() << ", AForm GradeToExecute: "
        << data.getGradeToExecute(); 
    return (os);
}