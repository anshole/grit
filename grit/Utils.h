#pragma once

#include <string>
#include <vector>
#include "Mesh.h"

namespace grit {

	class Mesh;

	static bool DEBUG = true;

class Utils
{
public:
	Utils();
	~Utils();

	static void log(std::string message);
	static void exit(std::string message);
};

}