#include "Serializer.hpp"

int main(void)
{
    Serializer::Data test1;
    test1.name = "test1";
    Serializer::Data test2;
    test2.name = "test2";
    uintptr_t temp1 = Serializer::serialize(&test1);
    uintptr_t temp2 = Serializer::serialize(&test2);
    Serializer::Data *test3 = Serializer::deserialize(temp1);
    Serializer::Data *test4 = Serializer::deserialize(temp2);

    std::cout   << "=======Address test========" << std::endl;
    std::cout   << "test1 address: " << &test1 << " test1 name: " << test1.name << '\n'
                << "temp1 address: " << &temp1 << " temp1: "  << temp1 << '\n'
                << "test2 address: " << &test2 << " test2 name: " << test2.name<< '\n'
                << "temp2 address: " << &temp2 << " temp2: "  << temp2 << '\n'
                << "test3 address: " << test3 << " test3 name: " << test3->name << '\n'
                << "test4 address: " << test4 << " test4 name: " << test4->name << std::endl;
    std::cout << std::endl;

    test3->name = "test3";
    test4->name = "test4";
    std::cout   << "test1 address: " << &test1 << " test1 name: " << test1.name << '\n'
                << "temp1 address: " << &temp1 << " temp1: "  << temp1 << '\n'
                << "test2 address: " << &test2 << " test2 name: " << test2.name<< '\n'
                << "temp2 address: " << &temp2 << " temp2: "  << temp2 << '\n'
                << "test3 address: " << test3 << " test3 name: " << test3->name << '\n'
                << "test4 address: " << test4 << " test4 name: " << test4->name << std::endl;
    std::cout << std::endl;

    int i;
    if (temp1 > temp2)
    {
        i = temp1 - temp2;
        temp2 += i; 
    }
    else
    {
        i = temp2 - temp1;
        temp1 += i; 
    }

    test3 = Serializer::deserialize(temp1);
    test4 = Serializer::deserialize(temp2);

    std::cout   << "=======Address move test========" << std::endl;
    std::cout   << "test1 address: " << &test1 << " test1 name: " << test1.name << '\n'
                << "test2 address: " << &test2 << " test2 name: " << test2.name << '\n' << '\n'
                << "temp1 address: " << &temp1 << " temp1: "  << temp1 << '\n'
                << "temp2 address: " << &temp2 << " temp2: "  << temp2 << '\n' << '\n'
                << "test3 address: " << test3 << " test3 name: " << test3->name << '\n'
                << "test4 address: " << test4 << " test4 name: " << test4->name << std::endl;
    std::cout << std::endl;
}