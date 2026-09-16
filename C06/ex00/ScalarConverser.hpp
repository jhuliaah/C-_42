
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <climits>
#include <limits.h>
#include <float.h>
#include <cstdlib>
#include <cerrno>
#include <cctype>


class ScalarConverter {

    private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(ScalarConverter const &other);
    ScalarConverter& operator=(ScalarConverter const &other);
    
    public:    
    void ConvertTypes(const std::string& toConvert);
    
        static bool isPseudo(const std::string& toConvert);
		static bool isChar(const std::string& toConvert);
		static bool isInt(const std::string& toConvert);
		static bool isFloat(const std::string& toConvert);
		static bool isDouble(const std::string& toConvert);

		static void convertPseudo(const std::string& toConvert);
		static void convertChar(const std::string& toConvert);
		static void convertInt(const std::string& toConvert);
		static void convertFloat(const std::string& toConvert);
		static void convertDouble(const std::string& toConvert);

		static void convert(const std::string& toConvert);


};














#endif
