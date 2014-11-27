#ifndef DYNARRAY_H_
#define DYNARRAY_H_

#include <vector>

template<typename T>
class dynArray {
	using array_type = std::vector<T>;
	using value_type = typename array_type::value_type;
	using iterator = typename array_type::iterator;
	using reference = typename array_type::reference;
	using const_reference = typename array_type::const_reference;
	using size_type = typename array_type::size_type;


	array_type vector { };

public:
	inline void push_back(value_type const& val) {
		vector.push_back(val);
	}

	//Element Access
	inline reference at(int n) {
		return vector.at(n);
	}

	inline const_reference at(int n) const {
		return vector.at(n);
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

	inline iterator end() {
		return vector.end();
	}

	//Capacity

	//Modifiers

};

#endif

