
#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::~Weapon(void) {}

Weapon::Weapon(const std::string& type) {	_type = type;	}

const std::string& Weapon::getType(void) const {	return (_type);	}

void Weapon::setType(std::string type) {	_type = type;	}
