#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    {
        std::cout   << "===========operator test==========" << std::endl;
        ShrubberyCreationForm shrubbery("shrubbery");
        PresidentialPardonForm president("president");
        RobotomyRequestForm robot("robot");
        std::cout   << std::endl;

        std::cout   << shrubbery << std::endl;
        std::cout   << president << std::endl;
        std::cout   << robot << std::endl;
        std::cout   << std::endl;
    }

    // {
    //     std::cout   << "======= signed, execute grade 1 test =========" << std::endl;
    //     Bureaucrat max_grade("max", 1);
    //     ShrubberyCreationForm shrubbery("shrubbery");
    //     PresidentialPardonForm president("president");
    //     RobotomyRequestForm robot("robot");
    //     std::cout   << std::endl;

    //     try {
    //         shrubbery.beSigned(max_grade);
    //         std::cout << shrubbery.getName() << ": try signed success" << std::endl;
    //         try {
    //             shrubbery.execute(max_grade);
    //             std::cout << shrubbery.getName() << ": try execute success" << std::endl;
    //         } catch (std::exception &e) {
    //             std::cout << e.what() << std::endl;
    //         }
    //     } catch (std::exception &e) {
    //         std::cout << e.what() << std::endl;
    //     }
    //     std::cout   << std::endl;

    //     try {
    //         president.beSigned(max_grade);;
    //         std::cout << president.getName() << ": try signed success" << std::endl;
    //         try {
    //             president.execute(max_grade);
    //             std::cout << president.getName() << ": try execute success" << std::endl;
    //         } catch (std::exception &e) {
    //             std::cout << e.what() << std::endl;
    //         }
    //     } catch (std::exception &e) {
    //         std::cout << e.what() << std::endl;
    //     }
    //     std::cout   << std::endl;

    //     try {
    //         robot.beSigned(max_grade);;
    //         std::cout << robot.getName() << ": try signed success" << std::endl;
    //         try {
    //             robot.execute(max_grade);
    //             std::cout << robot.getName() << ": try execute success" << std::endl;
    //         } catch (std::exception &e) {
    //             std::cout << e.what() << std::endl;
    //         }
    //     } catch (std::exception &e) {
    //         std::cout << e.what() << std::endl;
    //     }
    //     std::cout   << std::endl;
    // }
    // std::cout   << std::endl;

    {
        std::cout   << "======= signed, execute grade 1 test =========" << std::endl;
        Bureaucrat max_grade("max", 1);
        ShrubberyCreationForm shrubbery("shrubbery");
        PresidentialPardonForm president("president");
        RobotomyRequestForm robot("robot");
        std::cout   << std::endl;

        max_grade.signForm(shrubbery);
        max_grade.executeForm(shrubbery);
        std::cout   << std::endl;
        
        max_grade.signForm(president);
        max_grade.executeForm(president);
        std::cout   << std::endl;

        max_grade.signForm(robot);
        max_grade.executeForm(robot);
        std::cout   << std::endl;
    }
    std::cout   << std::endl;

    // {
    //     std::cout   << "======= unsigned, execute grade 150 test =========" << std::endl;
    //     Bureaucrat min_grade("min", 150);
    //     ShrubberyCreationForm shrubbery("shrubbery");
    //     PresidentialPardonForm president("president");
    //     RobotomyRequestForm robot("robot");
    //     std::cout   << std::endl;

    //     try {
    //         shrubbery.beSigned(min_grade);
    //         std::cout << shrubbery.getName() << ": try signed success" << std::endl;
    //         try {
    //             shrubbery.execute(min_grade);
    //             std::cout << shrubbery.getName() << ": try execute success" << std::endl;
    //         } catch (std::exception &e) {
    //             std::cout << e.what() << std::endl;
    //         }
    //     } catch (std::exception &e) {
    //         std::cout << e.what() << std::endl;
    //     }
    //     std::cout   << std::endl;

    //     try {
    //         president.beSigned(min_grade);;
    //         std::cout << president.getName() << ": try signed success" << std::endl;
    //         try {
    //             president.execute(min_grade);
    //             std::cout << president.getName() << ": try execute success" << std::endl;
    //         } catch (std::exception &e) {
    //             std::cout << e.what() << std::endl;
    //         }
    //     } catch (std::exception &e) {
    //         std::cout << e.what() << std::endl;
    //     }
    //     std::cout   << std::endl;

    //     try {
    //         robot.beSigned(min_grade);;
    //         std::cout << robot.getName() << ": try signed success" << std::endl;
    //         try {
    //             robot.execute(min_grade);
    //             std::cout << robot.getName() << ": try execute success" << std::endl;
    //         } catch (std::exception &e) {
    //             std::cout << e.what() << std::endl;
    //         }
    //     } catch (std::exception &e) {
    //         std::cout << e.what() << std::endl;
    //     }
    //     std::cout   << std::endl;
    // }
    // std::cout   << std::endl;

    {
        std::cout   << "======= unsigned, execute grade 150 test =========" << std::endl;
        Bureaucrat min_grade("min", 150);
        ShrubberyCreationForm shrubbery("shrubbery");
        PresidentialPardonForm president("president");
        RobotomyRequestForm robot("robot");
        std::cout   << std::endl;

        min_grade.signForm(shrubbery);
        min_grade.executeForm(shrubbery);
        std::cout   << std::endl;
        
        min_grade.signForm(president);
        min_grade.executeForm(president);
        std::cout   << std::endl;

        min_grade.signForm(robot);
        min_grade.executeForm(robot);
        std::cout   << std::endl;
    }
    std::cout   << std::endl;

    // {
    //     std::cout   << "======= signed, execute grade 150 test =========" << std::endl;
    //     Bureaucrat min_grade("min", 150);
    //     Bureaucrat max_grade("max", 1);
    //     ShrubberyCreationForm shrubbery("shrubbery");
    //     PresidentialPardonForm president("president");
    //     RobotomyRequestForm robot("robot");
    //     std::cout   << std::endl;

    //     try {
    //         shrubbery.beSigned(max_grade);
    //         std::cout << shrubbery.getName() << ": try signed success" << std::endl;
    //         try {
    //             shrubbery.execute(min_grade);
    //             std::cout << shrubbery.getName() << ": try execute success" << std::endl;
    //         } catch (std::exception &e) {
    //             std::cout << e.what() << std::endl;
    //         }
    //     } catch (std::exception &e) {
    //         std::cout << e.what() << std::endl;
    //     }
    //     std::cout   << std::endl;

    //     try {
    //         president.beSigned(max_grade);;
    //         std::cout << president.getName() << ": try signed success" << std::endl;
    //         try {
    //             president.execute(min_grade);
    //             std::cout << president.getName() << ": try execute success" << std::endl;
    //         } catch (std::exception &e) {
    //             std::cout << e.what() << std::endl;
    //         }
    //     } catch (std::exception &e) {
    //         std::cout << e.what() << std::endl;
    //     }
    //     std::cout   << std::endl;

    //     try {
    //         robot.beSigned(max_grade);;
    //         std::cout << robot.getName() << ": try signed success" << std::endl;
    //         try {
    //             robot.execute(min_grade);
    //             std::cout << robot.getName() << ": try execute success" << std::endl;
    //         } catch (std::exception &e) {
    //             std::cout << e.what() << std::endl;
    //         }
    //     } catch (std::exception &e) {
    //         std::cout << e.what() << std::endl;
    //     }
    //     std::cout   << std::endl;
    // }
    // std::cout   << std::endl;

    {
        std::cout   << "======= signed, execute grade 150 test =========" << std::endl;
        Bureaucrat min_grade("min", 150);
        Bureaucrat max_grade("max", 1);
        ShrubberyCreationForm shrubbery("shrubbery");
        PresidentialPardonForm president("president");
        RobotomyRequestForm robot("robot");
        std::cout   << std::endl;

        max_grade.signForm(shrubbery);
        min_grade.executeForm(shrubbery);
        std::cout   << std::endl;
        
        max_grade.signForm(president);
        min_grade.executeForm(president);
        std::cout   << std::endl;

        max_grade.signForm(robot);
        min_grade.executeForm(robot);
        std::cout   << std::endl;        
    }
    std::cout   << std::endl;

    // {
    //     std::cout   << "======= unsigned, execute grade 1 test =========" << std::endl;
    //     Bureaucrat max_grade("max", 1);
    //     ShrubberyCreationForm shrubbery("shrubbery");
    //     PresidentialPardonForm president("president");
    //     RobotomyRequestForm robot("robot");
    //     std::cout   << std::endl;

    //     try {
    //         shrubbery.execute(max_grade);
    //         std::cout << shrubbery.getName() << ": try execute success" << std::endl;
    //     } catch (std::exception &e) {
    //         std::cout << e.what() << std::endl;
    //     }
    //     std::cout   << std::endl;

    //     try {
    //         president.execute(max_grade);
    //         std::cout << president.getName() << ": try execute success" << std::endl;
    //     } catch (std::exception &e) {
    //         std::cout << e.what() << std::endl;
    //     }
    //     std::cout   << std::endl;

    //     try {
    //         robot.execute(max_grade);
    //         std::cout << robot.getName() << ": try execute success" << std::endl;
    //     } catch (std::exception &e) {
    //         std::cout << e.what() << std::endl;
    //     }
    //     std::cout   << std::endl;
    // }
    // std::cout   << std::endl;

    {
        std::cout   << "======= unsigned, execute grade 1 test =========" << std::endl;
        Bureaucrat max_grade("max", 1);
        ShrubberyCreationForm shrubbery("shrubbery");
        PresidentialPardonForm president("president");
        RobotomyRequestForm robot("robot");
        std::cout   << std::endl;

        max_grade.executeForm(shrubbery);
        std::cout   << std::endl;
        
        max_grade.executeForm(president);
        std::cout   << std::endl;

        max_grade.executeForm(robot);
        std::cout   << std::endl; 
    }

    return 0;
}