
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"


int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}



/*
int	main()
{
	{
		Weapon _weapon = Weapon("Handhook");

		HumanA Jaqueline("Jaque", _weapon);
		Jaqueline.attack();
		_weapon.setType(".38");
		Jaqueline.attack();
	}

	{
		Weapon _weapon = Weapon("Torch");

		HumanB Jimothy("Jim");
		Jimothy.attack();
		Jimothy.setWeapon(_weapon);
		Jimothy.attack();
		_weapon.setType("Spike and Fire");
		Jimothy.attack();
	}
	return (0);
}



Por Que Os Blocos Anônimos?
Os blocos de chaves extras ({ }) no main são chamados de blocos de escopo ou escopos anônimos.
O C++ usa essa técnica pelos seguintes motivos:

Controle de Tempo de Vida (Destrutores):
Quando a execução chega ao final do primeiro }:
bob (HumanA) é destruído.
club (Weapon) é destruída.

Quando a execução chega ao final do segundo }:
jim (HumanB) é destruído.
club (Weapon) é destruída.

Isso garante que a destruição (~HumanA(), ~HumanB(), ~Weapon()) do primeiro cenário não interfira 
ou se misture com a criação/destruição do segundo cenário no log de saída.

Reutilização de Nome: Permite que você declare a variável Weapon club duas vezes, uma em cada escopo, 
sem conflito de nome. Cada club existe apenas dentro de seu respectivo bloco.

Em resumo, o objetivo principal desses blocos é garantir que cada teste (HumanA vs. HumanB) seja 
isolado e que os destrutores sejam chamados imediatamente após o teste, limpando a memória e 
produzindo um log de teste claro.

*/