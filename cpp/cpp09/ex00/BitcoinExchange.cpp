#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { (void)other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        (void)other;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::Formatcheck(std::string data, FieldType type)
{

    if (type == KEY)
    {
        if (data.length() != 10)
            return (false);
        if (data[4] != '-' || data[7] != '-')
            return (false);
        for (int i = 0; i < 10; i++)
        {
            if (i == 4 || i == 7)
                continue ;
            if (!std::isdigit(data[i]))
                return (false);
        }
        
        int year = std::atoi(data.substr(0, 4).c_str());
        int month = std::atoi(data.substr(5, 2).c_str());
        int day = std::atoi(data.substr(8, 2).c_str());

        if (year > 2025)
            return (false);
        if (month < 1 || month > 12)
            return (false);
        if (day < 1 || day > 31)
            return (false);
    }
    else if (type == VALUE || type == IN_VALUE)
    {
        double num;
        std::istringstream iss(data);

        iss >> num;
        if (!iss.eof()|| iss.fail())
        {
            if (type == IN_VALUE)
                std::cerr   << "Error: file data error." << std::endl;
            return (false);
        }
        if (type == IN_VALUE && (num > 1000.0 || num < 0.0))
        {
            if (num < 0.0)
                std::cerr   << "Error: not a positive number." << std::endl;
            else
                std::cerr   << "Error: too large a number." << std::endl;
            return (false);
        }
    }
    return (true);
}

bool BitcoinExchange::loadDB(std::string& data, size_t pos)
{
    std::string key;
    std::string ValStr;
    double val;

    if (pos == std::string::npos)
    {
        std::cerr   << "Error: DataBase file data error." << std::endl;
        return (false);
    }
    key = data.substr(0, pos);
    if (!Formatcheck(key, KEY))
    {
        std::cerr   << "Error: DataBase file date data error." << std::endl;
        return (false);
    }
    ValStr = data.substr(pos + 1);
    if (!Formatcheck(ValStr, VALUE))
    {
        std::cerr   << "Error: DataBase file value data error." << std::endl;
        return (false);
    }
    std::istringstream iss(ValStr);
    iss >> val;
    DB[key] = val;
    return (true);
}

bool BitcoinExchange::makeDB(std::string filename)
{
    size_t pos;
    std::string data;
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr   << "Error: DataBase file open error." << std::endl;
        return (false);
    }
    getline(file, data);
    while (getline(file, data))
    {
        pos = data.find(',');
        if (!loadDB(data, pos))
            return (false);
    }
    return (true);
}

bool BitcoinExchange::loadInput(std::string& data, size_t pos, std::string& key, double& in_val)
{
    std::string ValStr;
    key = data.substr(0, pos - 1);
    if (pos == std::string::npos)
    {
        std::cerr << "Error: bad input => " << data << std::endl;
        return (false);
    }
    if (!Formatcheck(key, KEY))
    {
        std::cerr   << "Error: bad input => " << key  << std::endl;
        return (false);
    }
    ValStr = data.substr(pos + 2);
    if (!Formatcheck(ValStr, IN_VALUE))
        return (false);
    std::istringstream iss(ValStr);

    iss >> in_val;
    return (true);
}

void BitcoinExchange::buybit(std::string filename)
{
    double in_val = 0.0;
    size_t pos;
    std::string data;
    std::string key = "";
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr   << "Error: input file open error." << std::endl;
        return ;
    }
    getline(file, data);
    while (getline(file, data))
    {
        pos = data.find('|');
        if (!loadInput(data, pos, key, in_val))
            continue ;
        std::map<std::string, double>::const_iterator it = DB.lower_bound(key);

        if (it != DB.end() && it->first != key)
        {
            if (it == DB.begin())
            {
                std::cerr << "Error: no exchange rate available before " << key << std::endl;
                continue ;
            }
            --it;
        }
        else if (it == DB.end())
            --it;
        std::cout << key << " => " << in_val << " = " << (in_val * it->second) << std::endl;
    }
}