#ifndef DYNARRAY_H_
#define DYNARRAY_H_

#include <vector>
#include <initializer_list>

template<typename T>
struct dynArray {
	using array_type = std::vector<T>;
	using value_type = typename array_type::value_type;
	using iterator = typename array_type::iterator;
	using const_iterator = typename array_type::const_iterator;
	using reverse_iterator = typename array_type::reverse_iterator;
	using const_reverse_iterator = typename array_type::const_reverse_iterator;
	using reference = typename array_type::reference;
	using const_reference = typename array_type::const_reference;
	using size_type = typename array_type::size_type;
	using difference_type = typename array_type::difference_type;

	dynArray() :
			vector() {
	}

	dynArray(std::initializer_list<T> init) :
			vector(init) {
	}

	dynArray(size_type count, value_type value) :
			vector(count, value) {

	}

	dynArray(iterator begin, iterator end) :
			vector(begin, end) {

	}

	dynArray(const_iterator cbegin, const_iterator cend) :
			vector(cbegin, cend) {

	}

	dynArray(reverse_iterator rbegin, reverse_iterator rend) :
			vector(rbegin, rend) {

	}

	dynArray(const_reverse_iterator crbegin, const_reverse_iterator crend) :
			vector(crbegin, crend) {

	}

	dynArray<value_type> makedynArray(std::initializer_list<T> init) {
		return dynArray(init);
	}

	//Element Access
	reference at(size_type pos) {
		return vector.at(pos);
	}

	const_reference at(size_type pos) const {
		return vector.at(pos);
	}

	reference operator[](difference_type pos) {
		if (pos < 0) {
			return *(end() + pos);
		} else {
			return at(pos);
		}
	}

	const_reference operator[](difference_type pos) const {
		if (pos < 0) {
			return *(cend() + pos);
		} else {
			return at(pos);
		}
	}

	reference front() {
		return vector.front();
	}

	const_reference front() const {
		return vector.front();
	}

	reference back() {
		return vector.back();
	}

	const_reference back() const {
		return vector.back();
	}

	T* data();
	const T* data() const;

	//Iterators

	iterator begin() {
		return vector.begin();
	}

	const_iterator begin() const {
		return vector.cbegin();
	}

	const_iterator cbegin() const {
		return vector.cbegin();
	}

	reverse_iterator rbegin() {
		return vector.rbegin();
	}

	const_reverse_iterator rbegin() const {
		return vector.crbegin();
	}

	const_reverse_iterator crbegin() const {
		return vector.crbegin();
	}

	iterator end() {
		return vector.end();
	}

	const_iterator end() const {
		return vector.cend();
	}

	const_iterator cend() const {
		return vector.cend();
	}

	reverse_iterator rend() {
		return vector.rend();
	}

	const_reverse_iterator rend() const {
		return vector.crend();
	}

	const_reverse_iterator crend() const {
		return vector.crend();
	}

	//Capacity

	bool empty() const {
		return vector.empty();
	}

	size_type size() const {
		return vector.size();
	}

	size_type capacity() const {
		return vector.capacity();
	}

	//Modifiers

	void clear() {
		vector.clear();
	}

	iterator erase(iterator pos) {
		return vector.erase(pos);
	}

	iterator erase(const_iterator pos) {
		return vector.erase(pos);
	}

	iterator erase(iterator first, iterator last) {
		return vector.erase(first, last);
	}

	iterator erase(const_iterator first, const_iterator last) {
		return vector.erase(first, last);
	}

	void push_back(const value_type& value) {
		vector.push_back(value);
	}

	void pop_back() {
		vector.pop_back();
	}

	void resize(size_type count) {
		vector.resize(count);
	}

	void resize(size_type count, const value_type& value) {
		vector.resize(count, value);
	}

private:
	array_type vector { };
};

#endif

