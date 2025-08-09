#include "Intern.hpp"

Intern::Intern() { std::cout   << "Intern default constructor called"  << std::endl; }

Intern::Intern(const Intern& other)
{
	std::cout   << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout   << "Intern copy assignment operator called" << std::endl;
	if (&other != this)
		*this = other;
	return (*this);
}

Intern::~Intern() { std::cout << "Intern destructor called" << std::endl; }

AForm* Intern::makeRobotomyRequestForm(std::string target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeShrubberyCreationForm(std::string target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makePresidentialPardonForm(std::string target) const
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string form, std::string target) const
{
	std::string formType[3] = {"RobotomyRequest", "ShrubberyCreation", "PresidentialPardon"};
	AForm* (Intern::*formmaker[3])(std::string target) const =
	{
		&Intern::makeRobotomyRequestForm,
		&Intern::makeShrubberyCreationForm,
		&Intern::makePresidentialPardonForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (formType[i] == form)
			return ((this->*formmaker[i])(target));
	}
	std::cout	<< "Form: " << form << "not found" << std::endl;
	return (NULL);
}