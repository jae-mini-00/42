#ifndef INTERN_HPP
#define INTERN_HPP

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm *makeRobotomyRequestForm(std::string target) const;
		AForm *makeShrubberyCreationForm(std::string target) const;
		AForm *makePresidentialPardonForm(std::string target) const;

	public:
		// 생성자, 소멸자, 대입연산자
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		// 매서드
		AForm *makeForm(std::string form, std::string target) const;
};

#endif