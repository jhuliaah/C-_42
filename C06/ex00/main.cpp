#include "ScalarConverser.hpp"

static void runTests(void) {
	const char *tests[] = {
		"0", "42", "-42", "127", "-128", "255",
		"42.0f", "-4.2f", "0.0f", "nanf", "+inff", "-inff",
		"42.0", "-4.2", "0.0", "nan", "+inf", "-inf",
		"a", "z", " ", "\n",
		"2147483648", "-2147483649",
		"42.42e5", "abc", "42.f", "42."
	};
	size_t count = sizeof(tests) / sizeof(tests[0]);

	for (size_t i = 0; i < count; i++) {
		std::cout << "==== \"" << tests[i] << "\" ====" << std::endl;
		ScalarConverter::convert(tests[i]);
		std::cout << std::endl;
	}
}

int main(int argc, char **argv) {
	if (argc == 1) {
		runTests();
		return (0);
	}
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
