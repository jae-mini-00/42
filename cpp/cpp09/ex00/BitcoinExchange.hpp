#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>


class BitcoinExchange
{
    private:
        std::map<std::string, double> DB;
        enum FieldType
        {
            KEY,
            VALUE,
            IN_VALUE
        };    

        bool Formatcheck(std::string data, FieldType type);
        bool loadDB(std::string& data, size_t pos);
        bool loadInput(std::string& data, size_t pos, std::string& key, double& in_val);
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        bool makeDB(std::string filename);
        void buybit(std::string filename);
};


#endif