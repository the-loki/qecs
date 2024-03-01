//
// Created by loki on 2024/3/1.
//

#pragma once

#include <cstddef>
#include <string_view>

namespace qecs {

namespace internal {

template<typename>
struct fnv1a_traits;

template<>
struct fnv1a_traits<std::uint32_t> {
	using type = std::uint32_t;
	static constexpr std::uint32_t offset = 2166136261;
	static constexpr std::uint32_t prime = 16777619;
};

template<>
struct fnv1a_traits<std::uint64_t> {
	using type = std::uint64_t;
	static constexpr std::uint64_t offset = 14695981039346656037ull;
	static constexpr std::uint64_t prime = 1099511628211ull;
};

using traits_type = fnv1a_traits<id_type>;
using hash_value_type = id_type;
}

template<typename Char>
[[maybe_unused]] constexpr internal::hash_value_type hash(std::basic_string_view<Char> str) {
	internal::hash_value_type hash_value = 0u;

	for (auto length = 0; length < str.length(); ++length) {
		hash_value = (hash_value ^ static_cast<internal::traits_type::type>(str[length]))*internal::traits_type::prime;
	}

	return hash_value;
}

}