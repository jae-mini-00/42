#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat max("max", 1);
    AForm* rrf;
    AForm* ppf;
    AForm* scf;
    AForm* test1;


    std::cout   << "=======RobotomyRequestForm test=========" << std::endl;
    rrf = someRandomIntern.makeForm("RobotomyRequest", "Bender1");
    if (rrf) {
        max.signForm(*rrf);
        max.executeForm(*rrf);
        std::cout   << *rrf << std::endl;
    }
    std::cout   << std::endl;

    std::cout   << "=======PresidentialPardonForm test=========" << std::endl;
    ppf = someRandomIntern.makeForm("PresidentialPardon", "Bender2");
    if (ppf) {    
        max.signForm(*ppf);
        max.executeForm(*ppf);
        std::cout   << *ppf << std::endl;
    }
    std::cout   << std::endl;

    std::cout   << "=======ShrubberyCreation test=========" << std::endl;
    scf = someRandomIntern.makeForm("ShrubberyCreation", "Bender3");
    if (scf) {
        max.signForm(*scf);
        max.executeForm(*scf);
        std::cout   << *scf << std::endl;
    }
    std::cout   << std::endl;

    std::cout   << "=======Not found Form test=========" << std::endl;
    test1 = someRandomIntern.makeForm("test1", "Bender3");
    if (test1) {    
        max.signForm(*scf);
        max.executeForm(*scf);
        std::cout   << *test1 << std::endl;
    }
    std::cout   << std::endl;
    
    delete rrf;
    delete ppf;
    delete scf;
    delete test1;

    return 0;
}