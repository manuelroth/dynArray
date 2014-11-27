#include "dynArray.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

void testPushBack() {
	dynArray<int> v { };

	v.push_back(7);

	ASSERT_EQUAL(7, v.at(0));
}

//Element Access
void testAt() {
	dynArray<int> v { 1, 2 };
	ASSERT_EQUAL(2, v.at(1));
}

//Iterators


//Capacity

void runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testPushBack));
	s.push_back(CUTE(testAt));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
	runAllTests(argc, argv);
	return 0;
}
