//
// Created by loki on 2024/3/2.
//


#pragma once

#include <qecs/core/config.hpp>
#include <qecs/core/segment_list.hpp>

namespace qecs {

template<typename T>
struct sparse_set {
	using value_type = T;
	using index_type = id_type;

	segment_list<value_type> packed_;
	segment_list<index_type> sparse_;
};

}