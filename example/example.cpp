//
// Created by loki on 2024/2/29.
//

#include <qecs/qecs.hpp>
#include <iostream>



int main() {
	std::cout << qecs::type_index<void>::value << std::endl;
	std::cout << qecs::type_index<int>::value << std::endl;

	return 0;
}