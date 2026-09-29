#ifndef BTC_HPP
#define BTC_HPP

#include <iostream>
#include <map>
#include <fstream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <iomanip>
# include <sstream>

class BitcoinExchange {
    private:
    std::map<std::string, double> _data;

    public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    //error treatment

    class BadInputException : public std::exception {
        private:
        std::string _msg;
        
        public:
        BadInputException(const std::string &line)
        {
            std::ostringstream oss;
            oss << "bad input => " << line;
            _msg = oss.str();
        }
        virtual ~BadInputException() throw() {}
        virtual const char* what() const throw() {return _msg.c_str();}
    };

     class BadDateException : public std::exception {
        private:
        std::string _msg;
        
        public:
        BadDateException(const std::string &line)
        {
            std::ostringstream oss;
            oss << "bad date => " << line;
            _msg = oss.str();
        }
        virtual ~BadDateException() throw() {}
        virtual const char* what() const throw() {return _msg.c_str();}
    };

    class CsvFileNotFounded : public std::exception {
        public:
        virtual const char* what() const throw () { return "could not open the file.";}
    };

    class NotPositiveNumberException : public std::exception {
        public:
        virtual const char* what() const throw() { return "Not a positive Number.";}
    };

    class BitcoinDontExistException : public std::exception {
        public:
        virtual const char* what() const throw() { return "Bitcoin doesn't exist in this date";}
    };

    class LargeNumberException : public std::exception {
        public:
        virtual const char* what() const throw() { return "number too large";} 
    };

    //functions:

    std::map<std::string, double> fileConvert();
    void printMap();
    
    std::string mapKeyValid(std::string line);
    int validDateValue(std::string line);
    int validData(std::string line);
    int validValue(std::string line);
    void validFileLine(std::string line);

};
























#endif