#include <iostream>
#include <string>
#include "Array.hpp"

int main(void) {
	Array<int> empty;
	std::cout << "empty size: " << empty.size() << std::endl;

	Array<int> nums(5);
	for (size_t i = 0; i < nums.size(); i++)
		nums[i] = static_cast<int>(i * 10);

	Array<int> copy(nums);
	copy[0] = 999;

	std::cout << "nums: ";
	for (size_t i = 0; i < nums.size(); i++)
		std::cout << nums[i] << " ";
	std::cout << std::endl;

	std::cout << "copy: ";
	for (size_t i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	Array<int> assigned;
	assigned = nums;
	assigned[1] = 111;

	std::cout << "nums:     ";
	for (size_t i = 0; i < nums.size(); i++)
		std::cout << nums[i] << " ";
	std::cout << std::endl;

	std::cout << "assigned: ";
	for (size_t i = 0; i < assigned.size(); i++)
		std::cout << assigned[i] << " ";
	std::cout << std::endl;

	try {
		std::cout << nums[100] << std::endl;
	} catch (std::exception &e) {
		std::cout << "caught out-of-bounds access: " << e.what() << std::endl;
	}

	Array<std::string> strings(3);
	strings[0] = "foo";
	strings[1] = "bar";
	strings[2] = "baz";
	for (size_t i = 0; i < strings.size(); i++)
		std::cout << strings[i] << " ";
	std::cout << std::endl;

	return (0);
}
