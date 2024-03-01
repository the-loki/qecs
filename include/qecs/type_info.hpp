//
// Created by loki on 2024/2/29.
//


#pragma once

#include <qecs/config.hpp>
#include <qecs/string_hash.hpp>
#include <atomic>
#include <string_view>
#include <source_location>

namespace qecs {

template<typename T>
consteval auto stripped_type_name() {
	auto loc = std::source_location::current();
	std::string_view full_name = loc.function_name();

#ifdef _MSC_VER
	std::string_view end_tag = "(void)";
	std::string_view start_tag = "stripped_type_name<";
	auto start = full_name.find_first_not_of(' ', full_name.rfind(start_tag) + start_tag.length());
	auto type_name = full_name.substr(start, full_name.rfind(end_tag) - start);
#else
	std::string_view end_tag = ";]";
	std::string_view start_tag = "T = ";
	auto start = full_name.find_first_not_of(' ', full_name.rfind(start_tag) + start_tag.length());
	auto type_name = full_name.substr(start, full_name.find_first_of(end_tag, start) - start);
#endif

	return type_name;
}

template<typename T>
struct type_index {
	static constexpr auto value = qecs::hash(stripped_type_name<T>());
};

struct type_info final {};

}


