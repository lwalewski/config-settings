/*
 * Configuration Settings Library
 * https://github.com/lwalewski/config-settings.git
 *
 * Copyright (c) 2018 Lukasz Walewski. All rights reserved.
 * Distributed under the MIT License
 * http://opensource.org/licenses/MIT
 */

#ifndef TYPEDCONFIGSETTING_H_
#define TYPEDCONFIGSETTING_H_

#include <ostream>
#include <string>

template<typename T>
class TypedConfigSetting {

public:

	TypedConfigSetting(const T d, const char* n) :
			act(d),
			def(d),
			name(const_cast<char*>(n)) {
	}

	T operator=(const T rhs) {
		return act = rhs;
	}

	operator bool() const {
		return act;
	}

	operator int() const {
		return act;
	}

	operator char*() const {
		return act;
	}

	template<typename T1>
	friend std::ostream& operator<<(std::ostream&, const TypedConfigSetting<T1>&);

private:

	T act;
	T def;
	char* name;

};

template<typename T>
std::ostream& operator<<(std::ostream& os, const TypedConfigSetting<T>& c) {
	os << c.name << " [" << c.def << "] = " << c.act;
	return os;
}

#endif /* TYPEDCONFIGSETTING_H_ */
