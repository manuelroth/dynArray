#include "dynArray.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <vector>
#include <stdexcept>


//Element Access
void testAt() {
	dynArray<int> v { 1, 2 };

	ASSERT_EQUAL(2, v.at(1));
}

void testAtConst() {
	const dynArray<int> v { 1, 2 };

	ASSERT_EQUAL(2, v.at(1));
}

void testAtThrowsError() {
	dynArray<int> v { 1, 2 };

	ASSERT_THROWS(v.at(2), std::out_of_range);
}

void testFront() {
	dynArray<int> v { 1, 2 };

	ASSERT_EQUAL(1, v.front());
}

void testFrontConst() {
	const dynArray<int> v { 1, 2 };

	ASSERT_EQUAL(1, v.front());
}

void testBack() {
	dynArray<int> v { 1, 2 };

	ASSERT_EQUAL(2, v.back());
}

void testBackConst() {
	const dynArray<int> v { 1, 2 };

	ASSERT_EQUAL(2, v.back());
}

//Iterators

//Capacity

void testEmpty() {
	dynArray<double> v { };

	ASSERT(v.empty());
}

void testSize() {
	dynArray<double> v { 1, 2, 3, 4, 5 };

	ASSERT_EQUAL(5, v.size());
}

void testCapacity() {
	dynArray<double> v { 1, 2, 3, 4, 5 };

	ASSERT_EQUAL(5, v.capacity());
}

//Modifiers

void testClear() {
	dynArray<double> v { };

	v.push_back(1.0);
	v.clear();

	ASSERT(v.empty());
}

void testErasePositionIterator() {
	dynArray<int> v { 1, 2, 3, 4, 5 };

	v.erase(v.begin());

	ASSERT_EQUAL(2, *v.begin());
}

void testErasePositionConstIterator() {
	dynArray<long int> v { 1, 2, 3, 4, 5 };

	v.erase(v.cbegin() + 2);

	ASSERT_EQUAL(4, v.at(2));
}

void testEraseFirstLastIterator() {
	dynArray<double> v { 1, 2, 3, 4, 5 };

	v.erase(v.begin(), v.begin() + 3);

	ASSERT_EQUAL(4, *v.begin());
}

void testEraseFirstLastConstIterator() {
	dynArray<long double> v { 1, 2, 3, 4, 5 };

	v.erase(v.cbegin(), v.cbegin() + 3);

	ASSERT_EQUAL(5, v.at(1));
}

void testPushBack() {
	dynArray<int> v { };

	v.push_back(7);

	ASSERT_EQUAL(7, v.at(0));
}

void testPopBack() {
	dynArray<long double> v { 1, 2, 3, 4, 5 };

	v.pop_back();

	ASSERT_EQUAL(4, v.size());
}

void testResize() {
	dynArray<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

}

void runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testAt));
	s.push_back(CUTE(testEmpty));
	s.push_back(CUTE(testSize));
	s.push_back(CUTE(testCapacity));
	s.push_back(CUTE(testClear));
	s.push_back(CUTE(testEraseFirstLastIterator));
	s.push_back(CUTE(testErasePositionIterator));
	s.push_back(CUTE(testErasePositionConstIterator));
	s.push_back(CUTE(testEraseFirstLastConstIterator));
	s.push_back(CUTE(testPushBack));
	s.push_back(CUTE(testPopBack));
	s.push_back(CUTE(testAtThrowsError));
	s.push_back(CUTE(testFront));
	s.push_back(CUTE(testBack));
	s.push_back(CUTE(testBackConst));
	s.push_back(CUTE(testFrontConst));
	s.push_back(CUTE(testAtConst));
	s.push_back(CUTE(testAtThrowsError));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
	runAllTests(argc, argv);
	return 0;
}
