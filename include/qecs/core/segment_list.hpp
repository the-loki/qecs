//
// Created by loki on 2024/3/2.
//


#pragma once

#include <qecs/core/config.hpp>
#include <vector>

namespace qecs {
template<typename T, size_t PageSize = QECS_PAGE_SIZE>
struct segment_list {
	using value_type = T;

	T &operator[](size_t index);

	void assure();

	void shirnk();

	void push_back(value_type &&value);

	void push_back(const value_type &value);

	template<typename ...Args>
	void emplace_back(Args &&...args);

	T pop_back();

	[[nodiscard]] size_t size() const;
protected:
	size_t size_ = 0;
	std::vector<std::vector<value_type>> data_{};
};

template<typename T, size_t PageSize>
inline void segment_list<T, PageSize>::shirnk() {
	auto page_size = (size_/PageSize) + (size_%PageSize ? 1 : 0);

	if (page_size!=data_.size()) {
		data_.resize(page_size);
		data_.shrink_to_fit();
	}
}

template<typename T, size_t PageSize>
template<typename... Args>
inline void segment_list<T, PageSize>::emplace_back(Args &&... args) {
	push_back(value_type(std::forward<Args>(args)...));
}

template<typename T, size_t PageSize>
inline void segment_list<T, PageSize>::push_back(const value_type &value) {
	assure();
	data_.back()[(size_++)%PageSize] = value;
}

template<typename T, size_t PageSize>
inline void segment_list<T, PageSize>::push_back(value_type &&value) {
	assure();
	data_.back()[(size_++)%PageSize] = std::move(value);
}

template<typename T, size_t PageSize>
inline T segment_list<T, PageSize>::pop_back() {
	if (size_ > 0) {
		--size_;
		return this->operator[](size_);
	}
}

template<typename T, size_t PageSize>
inline void segment_list<T, PageSize>::assure() {
	using page_type = decltype(data_)::value_type;

	if (size_ >= PageSize*data_.size()) {
		data_.emplace_back(page_type(PageSize));
	}
}

template<typename T, size_t PageSize>
inline T &segment_list<T, PageSize>::operator[](size_t index) {
	return data_[index/PageSize][index%PageSize];
}

template<typename T, size_t PageSize>
size_t segment_list<T, PageSize>::size() const {
	return size_;
}

}