#include "dynArray.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <vector>
#include <stdexcept>
#include <string>

void testDefaultConstructor() {
	dynArray<std::string> v { };

	ASSERT(v.empty());
}

void testInitializerListConstructor() {
	dynArray<std::string> v { "a", "b", "c", "d" };

	ASSERT_EQUAL(4, v.size());
}

void testCountValueConstructor() {
	dynArray<std::string> v(5, "abcd");

	ASSERT_EQUAL("abcd", v.at(4));
}

void testIteratorConstructor() {
	dynArray<std::string> v1 { "a", "b", "c", "d" };
	dynArray<std::string> v2(v1.begin(), v1.end());

	ASSERT_EQUAL("d", v2.at(3));
}

void testConstIteratorConstructor() {
	const dynArray<std::string> v1 { "a", "b", "c", "d" };
	dynArray<std::string> v2(v1.cbegin(), v1.cend());

	ASSERT_EQUAL("a", v2.at(0));
}

void testReverseIteratorConstructor() {
	dynArray<std::string> v1 { "a", "b", "c", "d", "e" };
	dynArray<std::string> v2(v1.rbegin(), v1.rend());

	ASSERT_EQUAL("a", v2.at(4));
}

void testConstReverseIteratorConstructor() {
	const dynArray<std::string> v1 { "a", "b", "c", "d", "e" };
	dynArray<std::string> v2(v1.rbegin(), v1.rend());

	ASSERT_EQUAL("e", v2.at(0));
}

void testmakedynArray() {
	dynArray<std::string> v = makedynArray<std::string>({ "a", "b", "c", "d" });

	ASSERT_EQUAL("d", v.at(3));
}

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

void testIndexFirstElement() {
	dynArray<int> v { 1, 2, 3, 4, 5 };

	ASSERT_EQUAL(1, v[0]);
}

void testIndexLastElement() {
	dynArray<int> v { 1, 2, 3, 4, 5 };

	ASSERT_EQUAL(5, v[4]);
}

void testIndexFirstElementConst() {
	const dynArray<int> v { 1, 2, 3, 4, 5 };

	ASSERT_EQUAL(1, v[0]);
}

void testIndexLastElementConst() {
	const dynArray<int> v { 1, 2, 3, 4, 5 };

	ASSERT_EQUAL(5, v[4]);
}

void testNegativeIndexFirstElement() {
	dynArray<int> v { 1, 2, 3, 4, 5 };

	ASSERT_EQUAL(1, v[-(v.size())]);
}

void testNegativeIndexLastElement() {
	dynArray<int> v { 1, 2, 3, 4, 5 };

	ASSERT_EQUAL(5, v[-1]);
}

void testNegativeIndexFirstElementConst() {
	const dynArray<int> v { 1, 2, 3, 4, 5 };

	ASSERT_EQUAL(1, v[-(v.size())]);
}

void testNegativeIndexLastElementConst() {
	const dynArray<int> v { 1, 2, 3, 4, 5 };

	ASSERT_EQUAL(5, v[-1]);
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

void testIteratorBegin() {
	dynArray<std::string> v { "a", "b", "c", "d" };

	ASSERT_EQUAL("b", *(v.begin() + 1));
}

void testIteratorBeginConst() {
	const dynArray<std::string> v { "a", "b", "c", "d" };

	ASSERT_EQUAL("a", *v.begin());
}

void testConstIteratorBeginConst() {
	const dynArray<std::string> v { "a", "b", "c", "d" };

	ASSERT_EQUAL("b", *(v.cbegin() + 1));
}

void testReverseIteratorBegin() {
	dynArray<std::string> v { "a", "b", "c", "d" };

	ASSERT_EQUAL("d", *v.rbegin());
}

void testReverseIteratorBeginConst() {
	const dynArray<std::string> v { "a", "b", "c", "d" };

	ASSERT_EQUAL("c", *(v.rbegin() + 1));
}

void testConstReverseIteratorBeginConst() {
	const dynArray<std::string> v { "a", "b", "c", "d" };

	ASSERT_EQUAL("b", *(v.crbegin() + 2));
}

void testIteratorEnd() {
	dynArray<std::string> v { "a", "b", "c", "d" };

	ASSERT_EQUAL("d", *(v.end() - 1));
}

void testIteratorEndConst() {
	const dynArray<std::string> v { "a", "b", "c", "d" };

	ASSERT_EQUAL("c", *(v.end() - 2));
}

void testConstIteratorEndConst() {
	const dynArray<std::string> v { "a", "b", "c", "d" };

	ASSERT_EQUAL("b", *(v.cend() - 3));
}

void testReverseIteratorEnd() {
	dynArray<std::string> v { "a", "b", "c", "d" };

	ASSERT_EQUAL("a", *(v.rend() - 1));
}

void testReverseIteratorEndConst() {
	const dynArray<std::string> v { "a", "b", "c", "d" };

	ASSERT_EQUAL("b", *(v.rend() - 2));
}

void testConstReverseIteratorEndConst() {
	const dynArray<std::string> v { "a", "b", "c", "d" };

	ASSERT_EQUAL("c", *(v.crend() - 3));
}

void testDistanceAlgorithm(){
	dynArray<std::string> v {"e1", "e2"};
	auto actual = std::distance(v.end(), v.begin());
	ASSERT_EQUAL(-2, actual);
}

void testCopyAlgorithm(){
	dynArray<std::string> v1 {"e1", "e2"};
	dynArray<std::string> v2(2, "");

	std::copy(v1.begin(), v1.end(), v2.begin());

	ASSERT_EQUAL(2, v2.size());
}

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
	dynArray<int> v { 1, 2, 3, 4, 5 };

	v.resize(10);

	ASSERT_EQUAL(10, v.capacity());
}

void testResizeWithValue() {
	dynArray<double> v { 1, 2, 3, 4, 5 };

	v.resize(10, 5);

	ASSERT_EQUAL(5, v.at(9));
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
	s.push_back(CUTE(testResize));
	s.push_back(CUTE(testResizeWithValue));
	s.push_back(CUTE(testIteratorBegin));
	s.push_back(CUTE(testIteratorBeginConst));
	s.push_back(CUTE(testReverseIteratorBegin));
	s.push_back(CUTE(testReverseIteratorBeginConst));
	s.push_back(CUTE(testIteratorEnd));
	s.push_back(CUTE(testIteratorEndConst));
	s.push_back(CUTE(testConstIteratorEndConst));
	s.push_back(CUTE(testConstReverseIteratorBeginConst));
	s.push_back(CUTE(testConstIteratorBeginConst));
	s.push_back(CUTE(testReverseIteratorEnd));
	s.push_back(CUTE(testReverseIteratorEndConst));
	s.push_back(CUTE(testConstReverseIteratorEndConst));
	s.push_back(CUTE(testDefaultConstructor));
	s.push_back(CUTE(testInitializerListConstructor));
	s.push_back(CUTE(testCountValueConstructor));
	s.push_back(CUTE(testIteratorConstructor));
	s.push_back(CUTE(testConstIteratorConstructor));
	s.push_back(CUTE(testReverseIteratorConstructor));
	s.push_back(CUTE(testConstReverseIteratorConstructor));
	s.push_back(CUTE(testmakedynArray));
	s.push_back(CUTE(testNegativeIndexLastElement));
	s.push_back(CUTE(testNegativeIndexFirstElement));
	s.push_back(CUTE(testIndexFirstElement));
	s.push_back(CUTE(testIndexLastElement));
	s.push_back(CUTE(testIndexFirstElementConst));
	s.push_back(CUTE(testIndexLastElementConst));
	s.push_back(CUTE(testNegativeIndexFirstElementConst));
	s.push_back(CUTE(testNegativeIndexLastElementConst));
	s.push_back(CUTE(testDistanceAlgorithm));
	s.push_back(CUTE(testCopyAlgorithm));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
	runAllTests(argc, argv);
	return 0;
}
