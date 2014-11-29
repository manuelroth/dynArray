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

	dynArray() :
			vector() {
	}

	dynArray(std::initializer_list<T> init) :
			vector(init) {
	}

	dynArray(int count, value_type value) :
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
	inline reference at(size_type pos) {
		return vector.at(pos);
	}

	inline const_reference at(size_type pos) const {
		return vector.at(pos);
	}

	inline reference operator[](size_type pos) {
		return vector[pos];
	}

	inline const_reference operator[](size_type pos) const {
		return vector[pos];
	}

	inline reference front() {
		return vector.front();
	}

	inline const_reference front() const {
		return vector.front();
	}

	inline reference back() {
		return vector.back();
	}

	inline const_reference back() const {
		return vector.back();
	}

	T* data();
	const T* data() const;

	//Iterators

	inline iterator begin() {
		return vector.begin();
	}

	inline const_iterator begin() const {
		return vector.cbegin();
	}

	inline const_iterator cbegin() const {
		return vector.cbegin();
	}

	inline reverse_iterator rbegin() {
		return vector.rbegin();
	}

	inline const_reverse_iterator rbegin() const {
		return vector.crbegin();
	}

	inline const_reverse_iterator crbegin() const {
		return vector.crbegin();
	}

	inline iterator end() {
		return vector.end();
	}

	inline const_iterator end() const {
		return vector.cend();
	}

	inline const_iterator cend() const {
		return vector.cend();
	}

	inline reverse_iterator rend() {
		return vector.rend();
	}

	inline const_reverse_iterator rend() const {
		return vector.crend();
	}

	inline const_reverse_iterator crend() const {
		return vector.crend();
	}

	//Capacity

	inline bool empty() const {
		return vector.empty();
	}

	inline size_type size() const {
		return vector.size();
	}

	inline size_type capacity() const {
		return vector.capacity();
	}

	//Modifiers

	inline void clear() {
		vector.clear();
	}

	inline iterator erase(iterator pos) {
		return vector.erase(pos);
	}

	inline iterator erase(const_iterator pos) {
		return vector.erase(pos);
	}

	inline iterator erase(iterator first, iterator last) {
		return vector.erase(first, last);
	}

	inline iterator erase(const_iterator first, const_iterator last) {
		return vector.erase(first, last);
	}

	inline void push_back(const value_type& value) {
		vector.push_back(value);
	}

	inline void pop_back() {
		vector.pop_back();
	}

	inline void resize(size_type count) {
		vector.resize(count);
	}

	inline void resize(size_type count, const value_type& value) {
		vector.resize(count, value);
	}

private:
	array_type vector { };
};

#endif

