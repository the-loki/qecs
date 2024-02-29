//
// Created by loki on 2024/2/29.
//


#pragma once

#include <qecs/config.hpp>
#include <atomic>
#include <source_location>

namespace qecs {

struct type_index final {
	[[nodiscard]] static id_type next() noexcept {
		static std::atomic<id_type> index{};
		return index++;
	}
};

template<typename T>
struct type_hash final {

};

struct type_info final {};

}


