#include "dynArray.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <stdexcept>

void testPushBack() {
	dynArray<int> v { };

	v.push_back(7);

	ASSERT_EQUAL(7, v.at(0));
}

//Element Access
void testAt() {
	dynArray<int> v { 1, 2 };
	ASSERT_EQUAL(2, v.at(0));
	ASSERT_EQUAL(2, v.at(1));
}

void testAtConst() {
	const dynArray<int> v { 1, 2 };
	ASSERT_EQUAL(2, v.at(0));
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
	dynArray<double> dynArray { };
	std::vector<double> stdVector { };

	ASSERT_EQUAL(stdVector.empty(), dynArray.empty());
}

void testSize() {
	dynArray<double> dynArray { };
}

void runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testPushBack));
	s.push_back(CUTE(testAt));
	s.push_back(CUTE(testEmpty));
	s.push_back(CUTE(testAtThrowsError));
	s.push_back(CUTE(testFront));
	s.push_back(CUTE(testBack));
	s.push_back(CUTE(testBackConst));
	s.push_back(CUTE(testFrontConst));
	s.push_back(CUTE(testAtConst));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
	runAllTests(argc, argv);
	return 0;
}
