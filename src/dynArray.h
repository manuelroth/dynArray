#ifndef DYNARRAY_H_
#define DYNARRAY_H_

#include <vector>

template<typename T>
class dynArray {
	std::vector<T> vector { };

public:
	inline void push_back(T const& val) {
		vector.push_back(val);
	}

	inline T& at(int n) {
		return vector.at(n);
	}
};

#endif

