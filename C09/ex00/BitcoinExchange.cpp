
#include "BitcoinExchange.hpp"

// Reads data.csv ("date,exchange_rate") and stores each line in a map
// with the date as key and the exchange rate as value.
// Throws CsvFileNotFounded if the file can't be opened.
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

// Default constructor: loads the price database from data.csv.
BitcoinExchange::BitcoinExchange(): _data(fileConvert()){}

// Copy constructor: copies the price database.
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

// Assignment operator: copies the price database from another object.
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other)
		this->_data = other._data;
	return *this;
}

// Destructor: nothing to free, the map cleans itself up.
BitcoinExchange::~BitcoinExchange(){}

// validation

// Returns true if the year is a leap year (February has 29 days).
static bool isLeap(int year){
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}


// Checks the format of an input line: "YYYY-MM-DD | value".
// Only the layout is checked here (digits, '-', ' ', '|'), not if the
// date actually exists. Throws BadInputException on a malformed line.
int BitcoinExchange::validDateValue(std::string line)
{
    if (line.size() < 14)
        throw BadInputException(line);

            for (std::size_t i = 0; i < line.size(); i++)
            {
                if ((i <= 3) || (i >= 5 && i <= 6) || (i >= 8 && i <= 9))
                {
                    //check if the dates are digits
			        if (!(isdigit(static_cast<unsigned char>(line[i]))))
				    throw BadInputException(line);
	        	}
                else if (i == 4 || i == 7 || i == 11)
                {
                    //check the in-betweens
			        if (i == 4 || i == 7) 
                    {
				        if ((line[i]) != '-')
					        throw BadInputException(line);
			        } 
                    else 
                    {
				        if ((line[i]) != '|')
					        throw BadInputException(line);
			        }                
                }
                else if (i == 10 || i == 12)
                {
			        if (line[i] != ' ')
				        throw BadInputException(line);
		        }
		        else 
			        break;
            }
            return 0;
}


// Checks if the date is a real calendar date (month 1-12, correct number
// of days, leap years) and not before bitcoin existed (2009-01-02).
// Throws BadDateException or BitcoinDontExistException.
int BitcoinExchange::validData(std::string line){
	int year, month, day, maxDay;
	bool leap;

	year = atoi((line.substr(0, 4)).c_str());
	month = atoi((line.substr(5, 2)).c_str());
	day = atoi((line.substr(8, 2)).c_str());
	leap = isLeap(year);

	if (year < 2009 || (year == 2009 && (month < 1 || (month == 1 && day < 2))))
		throw BitcoinDontExistException();
	if (month == 2)
		maxDay = leap ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDay = 30;
	else
		maxDay = 31;

	if (month < 1 || month > 12 || day < 1 || day > maxDay)
		throw BadDateException(line);
	return 0;
}

// Returns true if the token is a valid number: only digits and at most
// one '.', with at least one digit. A leading '-' is accepted here so the
// caller can report it as "not a positive number".
static bool validNumberToken(const std::string &token){
	if (token.empty())
		return false;
	if (token[0] == '-')
		return true;
	bool dotSeen = false;
	bool digitSeen = false;
	for (std::size_t i = 0; i < token.size(); ++i){
		if (token[i] == '.'){
			if (dotSeen)
				return false;
			dotSeen = true;
		} else if (isdigit(static_cast<unsigned char>(token[i]))){
			digitSeen = true;
		} else {
			return false;
		}
	}
	return digitSeen;
}

// Checks the value after " | ": must be a number between 0 and 1000.
// Throws NotPositiveNumberException, BadInputException or LargeNumberException.
int BitcoinExchange::validValue(std::string line){
	std::string valueToken = line.substr(13, (line.size() - 13));
	if (valueToken.size() > 0 && valueToken[0] == '-')
		throw NotPositiveNumberException();
	if (!validNumberToken(valueToken))
		throw BadInputException(line);
	double value = atof(valueToken.c_str());
	if (value >= 0 && value <= 1000)
		return 0;
	throw LargeNumberException();
	return 0;
}

// If the date isn't in the database, walks back one day at a time until
// it finds the closest lower date that exists. Returns that date, or
// "Error" if it goes back before 2009-01-02.
std::string BitcoinExchange::mapKeyValid(std::string date){
	int year, month, day;
	std::string	dateValid = date;

	year = atoi((date.substr(0, 4)).c_str());
	month = atoi((date.substr(5, 2)).c_str());
	day = atoi((date.substr(8, 2)).c_str());

		while (this->_data.find(dateValid) == this->_data.end()){
			if (year < 2009 || (year == 2009 && month == 1 && day < 2))
				return "Error";

			if (day > 1) {
				day--;
			} else {
				if (month > 1)
					month--;
				else {
					month = 12;
					year--;
				}
				int maxDay;
				if (month == 2)
					maxDay = isLeap(year) ? 29 : 28;
				else if (month == 4 || month == 6 || month == 9 || month == 11)
					maxDay = 30;
				else
					maxDay = 31;
				day = maxDay;
			}
			std::ostringstream oss;
			oss << std::setw(4) << std::setfill('0') << year << '-' << std::setw(2) << month << '-' << std::setw(2) << day;
			dateValid = oss.str();
		}
	
	return dateValid;
}

// Validates one input line (format, date, value) and prints
// "date => value = value * exchange_rate" using the rate of that date
// (or the closest lower date). Any error is thrown to the caller.
void BitcoinExchange::validFileLine(std::string line){
	if (validDateValue(line))
		return ;
	if (validData(line))
		return ;
	if (validValue(line))
		return ;
	else {
		float value = 0;
		std::string date = line.substr(0, 10);
		std::string lineVal = line.substr(13, (line.size() - 13));
		std::map<std::string, double>::const_iterator it = this->_data.find(date);
		if (it == this->_data.end()){
			std::string key = mapKeyValid(date);
			if (key == "Error"){
				throw BitcoinDontExistException();
			} else {
				value = this->_data[key];
			}
		} else {
			value = it->second;
		}
		std::string _print = date + " => " + lineVal + " = ";
		
		float finalValue = (value * atof((line.substr(13, (line.size() - 13)).c_str())));
		std::cout << _print << finalValue << std::endl;
		return ;
	}
}

