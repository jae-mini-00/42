#include <iomanip>
#include "Array.hpp"

#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_RESET "\033[0m"
#define COLOR_BLUE "\033[34m"

int main(void)
{
    {
        std::cout   << COLOR_GREEN << "========default constructor test========\n" << COLOR_RESET << std::endl;
        Array<int> Default;
        std::cout   << std::endl;

        std::cout   << COLOR_BLUE << "    ========print test========\n" << COLOR_RESET << std::endl;
        try {
            for (int i = 0; i < 6; i++)
            {
                Default[i];
                std::cout << "  Default: "<< Default[i] << std::endl;
            } 
        } catch (std::exception &e) {
            std::cout   << "    " << e.what() << std::endl;
        }
        std::cout   << "    size(): " << Default.size() << std::endl;
        std::cout   << std::endl;
    }
    std::cout   << COLOR_RED << "\n================default constructor test end==================\n\n\n" << COLOR_RESET << std::endl;

    {
        std::cout   << COLOR_GREEN << "========constructor test========\n" << COLOR_RESET << std::endl;
        Array<int> Int(5);
        Array<double> Double(5);
        std::cout   << std::endl;

        std::cout   << std::fixed << std::setprecision(2);
        std::cout   << COLOR_BLUE << "    ========default test========\n" << COLOR_RESET << std::endl;
        try {
            for (int i = 0; i < 6; i++)
            {
                Int[i];
                Double[i];
                std::cout << "      Int: "<< Int[i] << ", Double: " << Double[i] << std::endl;
            } 
        } catch (std::exception &e) {
            std::cout   << "    " << e.what() << std::endl;
        }
        std::cout   << std::endl;

        std::cout   << COLOR_BLUE << "    ========operator[] test========\n" << COLOR_RESET << std::endl;
        for (int i = 0; i < 3; i++)
        {
            try {
                Int[i] = 42;
                std::cout << "      Int: "<< Int[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            try {
                Double[i] = 42.42;
                std::cout   << ", Double: " << Double[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            std::cout   << std::endl;
        }
        try {
            Int[10] = 42;
            std::cout << "      Int: "<< Int[10];
        } catch (std::exception &e) {
            std::cout   << "    " << e.what() << std::endl;
        }
        std::cout   << std::endl;

        std::cout   << COLOR_BLUE << "    ========print all========\n" << COLOR_RESET << std::endl;
        for (int i = 0; i < 6; i++)
        {
            try {
                Int[i];
                std::cout << "      Int: "<< Int[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            try {
                Double[i];
                std::cout   << ", Double: " << Double[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            std::cout   << std::endl;
        }
    }
    std::cout   << COLOR_RED << "\n================constructor test end==================\n\n\n" << COLOR_RESET << std::endl;

    {
        std::cout   << COLOR_GREEN << "========copy constructor test========\n" << COLOR_RESET << std::endl;
        Array<int> Int(5);
        std::cout   << std::endl;

        std::cout   << COLOR_BLUE << "    ========Int operator========\n" << COLOR_RESET << std::endl;
        for (int i = 0; i < 3; i++)
        {
            try {
                Int[i] = 4;
                std::cout << "          Int: "<< Int[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            std::cout   << std::endl;
        }
        std::cout   << std::endl;

        std::cout   << COLOR_BLUE << "========copy constructor========\n" << COLOR_RESET << std::endl;
        Array<int> Copy_Int(Int);
        std::cout   << std::endl;

        std::cout   << COLOR_BLUE << "    ========Before print all========\n" << COLOR_RESET << std::endl;
        for (int i = 0; i < 5; i++)
        {
            try {
                Int[i];
                std::cout << "      Int: "<< Int[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            try {
                Copy_Int[i];
                std::cout   << ", Copy_Int: " << Copy_Int[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            std::cout   << std::endl;
        }
        std::cout   << std::endl;

        std::cout   << COLOR_BLUE << "    ========Copy_Int operator========\n" << COLOR_RESET << std::endl;
        for (int i = 0; i < 3; i++)
        {
            try {
                Copy_Int[i] = 2;
                std::cout   << "        Copy_Int: " << Copy_Int[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            std::cout   << std::endl;
        }
        std::cout   << std::endl;

        std::cout   << COLOR_BLUE << "    ========After print all========\n" << COLOR_RESET << std::endl;
        for (int i = 0; i < 5; i++)
        {
            try {
                Int[i];
                std::cout << "      Int: "<< Int[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            try {
                Copy_Int[i];
                std::cout   << ", Copy_Int: " << Copy_Int[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            std::cout   << std::endl;
        }
        std::cout   << std::endl;
    }
    std::cout   << COLOR_RED << "\n================copy constructor test end==================\n\n\n" << COLOR_RESET << std::endl;

    {
        std::cout   << COLOR_GREEN << "========copy operator test========\n" << COLOR_RESET << std::endl;
        Array<int> Int(5);
        std::cout   << std::endl;

        std::cout   << COLOR_BLUE << "    ========Int operator========\n" << COLOR_RESET << std::endl;
        for (int i = 0; i < 3; i++)
        {
            try {
                Int[i] = 5;
                std::cout << "          Int: "<< Int[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            std::cout   << std::endl;
        }
        std::cout   << std::endl;

        std::cout   << COLOR_BLUE << "========copy operator========\n" << COLOR_RESET << std::endl;
        Array<int> Copy_Int(5);
        Copy_Int = Int;
        std::cout   << std::endl;

        std::cout   << COLOR_BLUE << "    ========Before print all========\n" << COLOR_RESET << std::endl;
        for (int i = 0; i < 5; i++)
        {
            try {
                Int[i];
                std::cout << "      Int: "<< Int[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            try {
                Copy_Int[i];
                std::cout   << ", Copy_Int: " << Copy_Int[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            std::cout   << std::endl;
        }
        std::cout   << std::endl;

        std::cout   << COLOR_BLUE << "    ========Copy_Int operator========\n" << COLOR_RESET << std::endl;
        for (int i = 0; i < 3; i++)
        {
            try {
                Copy_Int[i] = 2;
                std::cout   << "        Copy_Int: " << Copy_Int[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            std::cout   << std::endl;
        }
        std::cout   << std::endl;

        std::cout   << COLOR_BLUE << "    ========After print all========\n" << COLOR_RESET << std::endl;
        for (int i = 0; i < 5; i++)
        {
            try {
                Int[i];
                std::cout << "      Int: "<< Int[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            try {
                Copy_Int[i];
                std::cout   << ", Copy_Int: " << Copy_Int[i];
            } catch (std::exception &e) {
                std::cout   << "    " << e.what() << std::endl;
            }
            std::cout   << std::endl;
        }
        std::cout   << std::endl;
    }
    std::cout   << COLOR_RED << "\n================copy operator test end==================\n\n\n" << COLOR_RESET << std::endl;

    {
        std::cout   << COLOR_GREEN << "========const array test========\n" << COLOR_RESET << std::endl;
        const Array<int> const_Int(1);
        std::cout   << std::endl;

        std::cout   << COLOR_BLUE << "    ========print test========\n" << COLOR_RESET << std::endl;
        try {
            const_Int[0];
            std::cout << "      c_Int: "<< const_Int[0] << std::endl;
        } catch (std::exception &e) {
            std::cout   << "    " << e.what() << std::endl;
        }
        try {
            const_Int[1];
            std::cout << "      c_Int: "<< const_Int[1] << std::endl;
        } catch (std::exception &e) {
            std::cout   << "    " << e.what() << std::endl;
        }
        std::cout   << std::endl;
    }
    std::cout   << COLOR_RED << "\n================const array end==================\n" << COLOR_RESET << std::endl;

    
    return 0;
}