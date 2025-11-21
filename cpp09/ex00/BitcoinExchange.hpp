#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <stdexcept>

class BitcoinExchange
{

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange& operator=(const BitcoinExchange& rhs);
        ~BitcoinExchange();

        void processInputFile(const std::string& filename);

    private:
        std::map<std::string, double> _data;

        void loadDatabase();
        void validateDate(const std::string& date);
        void validateValue(double value);
};

#endif