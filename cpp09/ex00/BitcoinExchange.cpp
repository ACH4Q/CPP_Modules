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

void BitcoinExchange::processInputFile(const std::string& filename)
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "could not open file" << std::endl;
    }
    std::string line;
    if (std::getline(inputFile,line) && line != "date | value")
    {
        std::cerr << "Error : Invalid header" << std::endl;
    }
    while (std::getline(inputFile,line))
    {
        std::string seperator;
        std::string date;
        std::stringstream ss(line);
        double value;   
    }
    
}

void BitcoinExchange::validateDate(const std::string& date)
{

}

void BitcoinExchange::validateValue(const std::string& valueStr)
{
    
}