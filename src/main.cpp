/*
 * Configuration Settings Library
 * https://github.com/lwalewski/config-settings.git
 *
 * Copyright (c) 2018 Lukasz Walewski. All rights reserved.
 * Distributed under the MIT License
 * http://opensource.org/licenses/MIT
 */

#include <iostream>
#include <list>
#include "ConfigSetting.h"

int main() {

	ConfigSetting myFlag(false, "flag");
	myFlag = true; // assignment of a 'bool'
	bool b = myFlag; // implicit conversion to 'bool'

	ConfigSetting myCounter(17, "counter");
	myCounter = 5; // assignment of an 'int'
	int i = myCounter; // implicit conversion to 'int'

	ConfigSetting myChars("Hello world!", "letters");
	myChars = "real life"; // assignment of a 'char*'
	char* c = myChars; // implict conversion to 'char*'

	std::cout << "b = " << b << "\n";
	std::cout << "i = " << i << "\n";
	std::cout << "c = '" << c << "'\n";

	std::cout << "\n";

	// polymorphic usage of 'ConfigSetting'
	std::list<ConfigSetting> mySettings = { myCounter, myFlag, myChars };
	for (const ConfigSetting& s : mySettings)
		std::cout << s << "\n";

	return 0;
}
