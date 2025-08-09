#include "Form.hpp"

Form::Form() : name("NoName"), IsSigned(false), GradeToSign(150), GradeToExecute(150)
{ std::cout   << "Form default constructor called"  << std::endl; }

Form::Form(const std::string& name, int GradeToSign, int GradeToExecute) throw (Form::GradeTooHighException, Form::GradeTooLowException)
: name(name), IsSigned(false), GradeToSign(GradeToSign), GradeToExecute(GradeToExecute)
{
    std::cout   << "Form constructor called" << std::endl;
    if (GradeToSign > 150 || GradeToExecute > 150 || GradeToSign > 150)
        throw Form::GradeTooLowException(name);
    if (GradeToSign < 1 || GradeToExecute < 1 || GradeToSign < 1)
        throw Form::GradeTooHighException(name); 
        
}

Form::Form(const Form& other)
: name(other.name), IsSigned(other.IsSigned), GradeToSign(other.GradeToSign), GradeToExecute(other.GradeToExecute)
{ std::cout   << "Form copy constructor called" << std::endl; }

Form::~Form()
{ std::cout << "Form destructor called" << std::endl; }

Form& Form::operator=(const Form& other) 
{
    std::cout   << "Form copy assignment operator called" << std::endl;
    if (this != &other)
    {
        std::cout   << "Can't copy assignment name" << std::endl;
    }
    return *this;
}

std::string Form::getName() const { return (this->name); }

bool Form::getIsSigned() const { return (this->IsSigned); }

int Form::getGradeToSign() const { return (this->GradeToSign); }

int Form::getGradeToExecute() const { return (this->GradeToExecute); }

void Form::beSigned(const Bureaucrat& bureaucrat) throw (Form::GradeTooLowException)
{
    if (bureaucrat.getGrade() > GradeToSign)
        throw (Form::GradeTooLowException(bureaucrat.getName()));
    IsSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form &data)
{
    os  << "Form name: " << data.getName() << " Form IsSined: " << data.getIsSigned()
        << " Form GradeToSign: " << data.getGradeToSign() << " Form GradeToExecute: "
        << data.getGradeToExecute(); 
    return (os);
}