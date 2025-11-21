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
        if (ss >> date >> seperator && seperator == "|" && ss >> value)
        {
            try
            {
                validateDate(date);
                validateValue(value);
                std::map<std::string,double>::iterator it = _data.lower_bound(date);
                if (it == _data.end() || (it != _data.begin() && it->first != date))
                {
                    --it;
                }
                double result = value * it->second;
                std::cout << date << "--> " << value << "=" << result << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
        else
            std::cerr << "bad input" << std::endl;
    }
    
}

void BitcoinExchange::validateDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("invalid date");
    int year = std::atoi(date.substr(0,4).c_str());
    int month = std::atoi(date.substr(5,2).c_str());
    int day = std::atoi(date.substr(8,5).c_str());
    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1)
    {
        std::cerr << "invalid month or day or year" << std::endl;
    }
}

void BitcoinExchange::validateValue(double value)
{
    if (value < 1)
        throw std::runtime_error("value is too low min value is 1");
    else if (value > 1000)
        throw std::runtime_error("value to high max value is 1000");    
}