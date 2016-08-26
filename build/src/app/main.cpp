#include <iostream>
#include "OpeniPosFrontEnd.h"

using ActualFrontEnd = OpeniPosFrontEnd;

int main(int argc, char *argv[]) {
	int result = 0;
	try {
		auto front_end = std::make_shared<ActualFrontEnd>(argv[0]);
		front_end->run();
	}
	catch (std::runtime_error& e) {
		std::cout << "\nFailed. Exception = " << e.what();
		result = 1; // Failed
	}
	std::cout << "\nDone!";
	std::cout << "\n";
	return result;
}