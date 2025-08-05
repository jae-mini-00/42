#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150)
{
    std::cout   << "Bureaucrat default constructor called"  << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) throw(GradeTooHighException, GradeTooLowException)
: name(name), grade(grade)
{
    std::cout   << "Bureaucrat constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException(name);
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException(name);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
    std::cout   << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout   << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        std::cout   << "Can't copy assignment name" << std::endl;
        this->grade = other.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::IncrementGrade() throw(GradeTooHighException)
{
    if (this->grade <= 1)
        throw Bureaucrat::GradeTooHighException(name);
    this->grade--;
}

void Bureaucrat::DecrementGrade() throw(GradeTooLowException)
{
    if (this->grade >= 150)
        throw Bureaucrat::GradeTooLowException(name);
    this->grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &data)
{
    os << data.getName() << ", bureaucrat grade " << data.getGrade();
    return (os);
}