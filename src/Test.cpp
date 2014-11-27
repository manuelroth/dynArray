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
	s.push_back(CUTE(testEmpty));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
	runAllTests(argc, argv);
	return 0;
}
