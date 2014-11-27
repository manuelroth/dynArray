#ifndef DYNARRAY_H_
#define DYNARRAY_H_

#include <vector>

template<typename T>
class dynArray {
	using array_type = std::vector<T>;
	using value_type = typename array_type::value_type;
	using iterator = typename array_type::iterator;
	using reference = typename array_type::reference;
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

	inline reference back() {
		return vector.back();
	}

	inline reference front() {
		return vector.front();
	}

	inline reference operator[](int pos) {
		return vector[pos];
	}

	//Iterators

	inline iterator begin() {
		return vector.begin();
	}

	inline iterator end() {
		return vector.end();
	}

	//Capacity

	inline bool empty() const {
		return vector.empty();
	}

	inline size_type size() const {
		return vector.size();
	}

	inline size_type max_size() const {
		return vector.max_size();
	}

	inline void reserve( size_type size ){
		vector.reserve( size );
	}

	inline size_type capacity() const {
		return vector.capacity();
	}

	inline void shrink_to_fit(){
		vector.shrink_to_fit();
	}

	//Modifiers

};

#endif

