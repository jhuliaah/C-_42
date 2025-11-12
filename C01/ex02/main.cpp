
#include <iostream>

int	main(void)
{
	std::string initial = "HI THIS IS BRAIN";
	std::string* PTR = &initial;
	std::string& REF = initial;

	std::cout << "The memory address of the string is: " << &initial << std::endl;
	std::cout << "The memory adrees held by PTR is: " << PTR << std::endl;
	std::cout << "The memory adress held by REF is: " << &REF << std::endl;

	std::cout << "Value of the string is: " << initial << std::endl;
	std::cout << "Value pointed to by PTR is: " << *PTR << std::endl;
	std::cout << "Value pointed to by REF is: " << REF << std::endl;

}

/*
/ for the string, I had to access the address by using '&';
/ for the pointer, I had to only print the pointer, and the address was shown;
/ for the reference I had to do the same I did with the string;
	Item		Representação					Sintaxe de Declaração		Como Acessar o Valor
	Variável	Os dados em si.					std::string s;				s
	Ponteiro	Um endereço de memória (*).		std::string* p;				*p
	Referência	Um apelido (&).					std::string& r = s;			r
	the reference is just like giving a second name to the variable.
	The pointer is passing the local where the variable is saved.
*/