#include "Utils.h"

namespace grit {

Utils::Utils() {
}


Utils::~Utils() {
}

void Utils::log(std::string message) {
	if (DEBUG)
		fprintf(stdout, "[DEBUG] %s\n", message.c_str());
}

void Utils::exit(std::string message) {
	Utils::log(message);
	std::exit(1);
}

}