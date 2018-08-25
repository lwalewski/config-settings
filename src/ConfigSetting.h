/*
 * Configuration Settings Library
 * https://github.com/lwalewski/config-settings.git
 *
 * Copyright (c) 2018 Lukasz Walewski. All rights reserved.
 * Distributed under the MIT License
 * http://opensource.org/licenses/MIT
 */

#ifndef CONFIGSETTING_H_
#define CONFIGSETTING_H_

#include <ostream>
#include "TypedConfigSetting.h"

enum SettingType {
	Bool,
	Int,
	Char
};

class ConfigSetting {

public:

	ConfigSetting(const bool b, const char* n) :
			type(Bool),
			data(TypedConfigSetting<bool>(b, n)) {
	}

	operator bool() const {
		return data.b;
	}

	bool operator=(const bool rhs) {
		return data.b = rhs;
	}

	ConfigSetting(const int i, const char* n) :
			type(Int),
			data(TypedConfigSetting<int>(i, n)) {
	}

	operator int() const {
		return data.i;
	}

	int operator=(const int rhs) {
		return data.i = rhs;
	}

	ConfigSetting(const char* c, const char* n) :
			type(Char),
			data(TypedConfigSetting<char*>(const_cast<char*>(c), n)) {
	}

	operator char*() const {
		return data.c;
	}

	char* operator=(const char* rhs) {
		return data.c = const_cast<char*>(rhs);
	}

	friend std::ostream& operator<<(std::ostream&, const ConfigSetting&);

private:

	enum SettingType type;

	union U {

		U() {
		}

		U(const TypedConfigSetting<bool>& b) :
				b(b) {
		}

		U(const TypedConfigSetting<int>& i) :
				i(i) {
		}

		U(const TypedConfigSetting<char*>& c) :
				c(c) {
		}

		TypedConfigSetting<bool> b;
		TypedConfigSetting<int> i;
		TypedConfigSetting<char*> c;

	} data;

};

std::ostream& operator<<(std::ostream& os, const ConfigSetting& c) {
	switch (c.type) {
	case Bool:
		os << "bool " << c.data.b;
		break;
	case Int:
		os << "int " << c.data.i;
		break;
	case Char:
		os << "char " << c.data.c;
		break;
	default:
		os << "*** type " << c.type << " not implemented ***";
		break;
	}
	return os;
}

#endif /* CONFIGSETTING_H_ */
