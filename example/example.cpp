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
	std::string_view function_name = loc.function_name();

//	function_name.find_last_of('>')+1
	function_name.length()

	//auto value = function_name.substr(function_name.find_first_of("stripped_type_name") + 1, function_name.find_last_of('>'));

	return value;
}

int main(){
	constexpr auto a = stripped_type_name<std::vector<std::string_view>>();
	constexpr auto b = stripped_type_name<int>();
	constexpr auto c = stripped_type_name<float>();

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	return 0;
}