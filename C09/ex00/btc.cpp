
#include "btc.hpp"

std::map<std::string, double> BitcoinExchange::fileConvert() {
    std::ifstream fileIn;
    std::string line;
    std::map<std::string, double> data;

    fileIn.open("data.csv");
    if (fileIn.is_open())
    {
        std::getline(fileIn, line); //firstline
        while (std::getline(fileIn, line))
        {
            data[line.substr(0, 10)] = atof((line.substr(11, (line.size() - 11))).c_str());
        }
    }
    else
        throw CsvFileNotFounded();
    return data;
}


//constructors

BitcoinExchange::BitcoinExchange(): _data(fileConvert()){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other)
		this->_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

// validation

static bool isLeap(int year){
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}



