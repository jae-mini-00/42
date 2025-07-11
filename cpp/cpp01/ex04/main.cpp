
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

std::string    change_str(std::fstream& file, char *s1, char *s2)
{
    size_t  world_len = strlen(s1);
    size_t  pos;
    std::string line;
    std::string result;

    std::getline(file, line);
    while (1)
    {
        pos = line.find(s1);
        if (pos != std::string::npos)
        {
            line.erase(pos, world_len);
            line.insert(pos, s2);
        }
        else
        {
            result += line + '\n';
            if (!std::getline(file, line))
                break ;
        }
    }
    return (result);
}

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::fstream file(av[1], std::ios::in);
        if (!file)
            std::cout   << "Erorr: open err" << std::endl;
        else
        {
            std::string temp = change_str(file, av[2], av[3]);
            file.close();
            file.open(av[1], std::ios::out);
            file << temp;
        }
    }
    else
        std::cout   << "Erorr: Incorrect number of arguments." << std::endl;
    return (0);
}