#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private :
        std::string target;

        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    
    public :
        // 오류 객체
        class FileOpenException : public std::exception
	    {
            private :
                std::string file_name;

	        public:
                FileOpenException(std::string name) : file_name(name) {}
                ~FileOpenException() throw () {}

		        virtual const char *what() const throw()
		        {
                    std::cerr    << file_name;
			        return (" open error");
		        }
	    };
        // 생서자, 대입 연산자 및 소멸자
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
        // 매서드
        void execute(Bureaucrat const & executor) const;
};

#endif