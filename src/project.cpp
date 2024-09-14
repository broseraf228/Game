#include "project.hpp"

#include <iostream>

void log(const char file[], int line, int type, const char* message) {

	std::cout << file << " -> line " << line << " - " << type << " - " << message;
}