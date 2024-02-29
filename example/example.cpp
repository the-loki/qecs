//
// Created by loki on 2024/2/29.
//

#include <qecs/qecs.hpp>
#include <iostream>
#include <string_view>
#include <source_location>
#include <vector>

template<typename T>
constexpr auto stripped_type_name() {
	auto loc = std::source_location::current();
	std::string_view full_name = loc.function_name();

	std::string_view fun_name = "stripped_type_name";
	auto start = full_name.rfind(fun_name) + fun_name.length() + 1;
	auto value = full_name.substr(start, full_name.find_last_of('>') - start);

	return value;
}

int main(){
	constexpr auto a = stripped_type_name<void>();
	constexpr auto b = stripped_type_name<int>();
	constexpr auto c = stripped_type_name<float>();

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	return 0;
}