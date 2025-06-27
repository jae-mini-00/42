
#include "Harl.hpp"

int main(void)
{
    Harl    a;

    a.complain("DEBUG");
    a.complain("INFO");
    a.complain("WARNING");
    a.complain("ERROR");
    a.complain("DEBUG");
    a.complain("INFO");
    a.complain("WARNING");
    a.complain("ERROR");
    a.complain("AAA");
    a.complain("INFO");
    a.complain("WARNING");
    a.complain("ERROR");
    a.complain("DEBUG");
    return (0);
}