#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    try
    {
        loadDatabase();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (&other != this)
    {
        this->_data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("could not load database");
    std::string line;
    std::getline(file,line);
    while (std::getline(file,line))
    {
        std::string date;
        std::string ratestring;
        std::stringstream ss(line);
        double rate;

        if (std::getline(ss,date,',') && ss >> rate)
        {
            this->_data[date] = rate;
        }
    }
}

void BitcoinExchange::validateDate(const std::string& date)
{

}

void BitcoinExchange::validateValue(const std::string& valueStr)
{

}

void BitcoinExchange::processInputFile(const std::string& filename)
{

}