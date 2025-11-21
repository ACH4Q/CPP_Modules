#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>

class BitcoinExchange
{
private:
    private:
        std::map<std::string, double> _data;

        void loadDatabase();
        void validateDate(const std::string& date);
        void validateValue(const std::string& valueStr);
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    void processInputFile(const std::string& filename);
};



#endif