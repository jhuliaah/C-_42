#include <iostream>
#include "Serializer.hpp"

int main(void) {
	Data original;
	original.name = "Wednesday Addams";
	original.value = 42;

	uintptr_t raw = Serializer::serialize(&original);
	Data *deserialized = Serializer::deserialize(raw);

	std::cout << "Original address:     " << &original << std::endl;
	std::cout << "Deserialized address: " << deserialized << std::endl;
	std::cout << "Pointers are equal:   " << (&original == deserialized ? "yes" : "no") << std::endl;
	std::cout << "Name:  " << deserialized->name << std::endl;
	std::cout << "Value: " << deserialized->value << std::endl;

	deserialized->value = 100;
	std::cout << "Original value after modifying through deserialized: " << original.value << std::endl;

	Data second;
	second.name = "Gomez Addams";
	second.value = -7;
	uintptr_t rawSecond = Serializer::serialize(&second);
	Data *deserializedSecond = Serializer::deserialize(rawSecond);
	std::cout << "Second name:  " << deserializedSecond->name << std::endl;
	std::cout << "Second value: " << deserializedSecond->value << std::endl;
	std::cout << "First and second addresses differ: " << (&original != &second ? "yes" : "no") << std::endl;

	return (0);
}
