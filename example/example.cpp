//
// Created by loki on 2024/2/29.
//

#include <qecs/qecs.hpp>
#include <iostream>

int main() {
	qecs::segment_list<int> list;

	for (int i = 0; i < 10000; ++i) {
		list.push_back(i);
	}

	for (int i = 0; i < 10000; ++i) {
		auto value = list.pop_back();
		list.shirnk();
		std::cout << list.size() << std::endl;
	}

	return 0;
}