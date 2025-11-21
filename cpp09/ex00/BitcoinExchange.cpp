#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    try
    {
        loadDatabase();
    } catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
    if (this != &rhs)
    {
        this->_data = rhs._data;
    }
    return *this;
}

void BitcoinExchange::loadDatabase()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        double      rate;

        if (std::getline(ss, date, ',') && ss >> rate)
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
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(inputFile, line);

    while (std::getline(inputFile, line))
    {
        std::stringstream ss(line);
        std::string date, separator;
        double      value;

        if (ss >> date >> separator && separator == "|" && ss >> value)
        {
            try
            {
                validateDate(date);
                validateValue(value);

                std::map<std::string, double>::iterator it = _data.lower_bound(date);
                if (it == _data.end() || (it != _data.begin() && it->first != date)) {
                    --it;
                }
                double result = value * it->second;
                std::cout << date << " => " << value << " = " << result << std::endl;
            } catch (const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }
        } else
        {
            std::cerr << "Error: bad input => " << date << std::endl;
        }
    }
}

void BitcoinExchange::validateDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        throw std::runtime_error("Error: bad input => " + date);
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        throw std::runtime_error("Error: bad input => " + date);
    }
}

void BitcoinExchange::validateValue(double value)
{
    if (value < 0)
    {
        throw std::runtime_error("Error: not a positive number.");
    }
    if (value > 1000)
    {
        throw std::runtime_error("Error: too large a number.");
    }
}