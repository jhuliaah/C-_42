#include "ScalarConverser.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {(void)other;}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}


bool ScalarConverter::isPseudo(const std::string& toConvert) {
	const char* pseudo[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	
	for (int i = 0; i < 6; i++) {
		if (pseudo[i] == toConvert)
			return (true);
	}
	return (false);
}

bool ScalarConverter::isChar(const std::string& toConvert){
	if (toConvert.size() == 1 && !std::isdigit(toConvert[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string& toConvert){
	char		*end;
	long int	value;

	errno = 0;
	value = std::strtol(toConvert.c_str(), &end, 10);
	if (errno == ERANGE || *end != '\0' || end == toConvert.c_str())
		return false;
	if (value < INT_MIN || value > INT_MAX)
		return false;
	return true;
}

bool ScalarConverter::isFloat(const std::string& toConvert){
	char		*end;
	float		value;

	errno = 0;
	value = std::strtof(toConvert.c_str(), &end);
	(void)value;
	if (errno == ERANGE || end == toConvert.c_str())
		return false;
	if (*end == 'f' && *(end + 1) == '\0')
		return true;
	return false;
}

bool ScalarConverter::isDouble(const std::string& toConvert){
	char *end;
	errno = 0;
	
	std::strtod(toConvert.c_str(), &end);
	if (errno == ERANGE || *end != '\0' || end == toConvert.c_str())
		return (false);
	return (true);
}

void ScalarConverter::convertPseudo(const std::string& toConvert){
	std::cout << "char:\timpossible" << std::endl;
	std::cout << "int:\timpossible" << std::endl;
	if (toConvert == "-inf" || toConvert == "+inf" || toConvert == "nan") {
		std::cout << "float:\t" << toConvert << "f" << std::endl;
		std::cout << "double:\t" << toConvert << std::endl; 	
	}
	else {
		std::cout << "float:\t" << toConvert << std::endl;
		std::cout << "double:\t" << toConvert.substr(0, toConvert.size() - 1)  << std::endl; 	
	}
}

void ScalarConverter::convertChar(const std::string& toConvert){
	if (toConvert[0] > 31 && toConvert[0] < 127)
		std::cout << "char:\t" << "'" << toConvert[0] << "'" << std::endl;
	else
		std::cout << "char:\tNon displayable" << std::endl;
	std::cout << "int:\t" << static_cast<int>(toConvert[0]) << std::endl;
	std::cout << "float:\t" << static_cast<float>(toConvert[0]) << "f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(toConvert[0]) << std::endl;
}

void ScalarConverter::convertInt(const std::string& toConvert){
	double doubleValue = atof(toConvert.c_str());
	int	intValue = atoi(toConvert.c_str());

	if (intValue > 31 && intValue < 127)
		std::cout << "char:\t" << "'" << static_cast<char>(intValue) << "'" << std::endl;
	else if (intValue < -128 || intValue > 127)
		std::cout << "char:\timpossible" << std::endl;
	else
		std::cout << "char:\tNon displayable" << std::endl;
	std::cout << "int:\t" << intValue << std::endl;
	std::cout << "float:\t" << static_cast<float>(doubleValue) << "f" << std::endl;
	std::cout << "double:\t" << doubleValue << std::endl;
}

void ScalarConverter::convertFloat(const std::string& toConvert){
	double doubleValue = atof(toConvert.c_str());

	if (doubleValue > 31 && doubleValue < 127)
		std::cout << "char:\t" << "'" << static_cast<char>(doubleValue) << "'" << std::endl;
	else if (doubleValue < -128 || doubleValue > 127)
		std::cout << "char:\timpossible" << std::endl;
	else
		std::cout << "char:\tNon displayable" << std::endl;
	if (doubleValue > INT_MAX || doubleValue < INT_MIN)
		std::cout << "int:\timpossible" << std::endl;
	else
		std::cout << "int:\t" <<  static_cast<int>(doubleValue) << std::endl;
	std::cout << "float:\t" << static_cast<float>(doubleValue) << "f" << std::endl;
	std::cout << "double:\t" << doubleValue << std::endl;
}

void ScalarConverter::convertDouble(const std::string& toConvert){
	double doubleValue = atof(toConvert.c_str());
	
	if (doubleValue > 31 && doubleValue < 127)
		std::cout << "char:\t" << "'" << static_cast<char>(doubleValue) << "'" << std::endl;
	else if (doubleValue < -128 || doubleValue > 127)
		std::cout << "char:\timpossible" << std::endl;
	else
		std::cout << "char:\tNon displayable" << std::endl;
	if (doubleValue > INT_MAX || doubleValue < INT_MIN)
		std::cout << "int:\timpossible" << std::endl;
	else
		std::cout << "int:\t" <<  static_cast<int>(doubleValue) << std::endl;
	if (doubleValue > FLT_MAX || doubleValue < -FLT_MAX)
		std::cout << "float:\timpossible" << std::endl;
	else
		std::cout << "float:\t" << static_cast<float>(doubleValue) << "f" << std::endl;
	std::cout << "double:\t" << doubleValue << std::endl;
}


//==========================

void ScalarConverter::convert(const std::string& toConvert){
	std::cout << std::fixed << std::setprecision(1);

	if (isPseudo(toConvert))
		convertPseudo(toConvert);
	else if (isChar(toConvert))
		convertChar(toConvert);
	else if (isInt(toConvert))
		convertInt(toConvert);
	else if (isFloat(toConvert))
		convertFloat(toConvert);
	else if (isDouble(toConvert))
		convertDouble(toConvert);
	else {
		std::cout << "char:\timpossible" << std::endl;
		std::cout << "int:\timpossible" << std::endl;
		std::cout << "float:\timpossible" << std::endl;
		std::cout << "double:\timpossible" << std::endl;
	}
}