#pragma once

#include <iostream>

////////////////////////////////////////////////////////////////////////
// USEFUL MACROS
////////////////////////////////////////////////////////////////////////

#define Kilobytes(x) (1024L * x)
#define Megabytes(x) (1024L * Kilobytes(x))
#define Gigabytes(x) (1024L * Megabytes(x))
#define Terabytes(x) (1024L * Gigabytes(x))

#define ArrayCount(Array) (sizeof(Array) / sizeof((Array)[0]))


////////////////////////////////////////////////////////////////////////
// CONSTANTS
////////////////////////////////////////////////////////////////////////

#define MAX_TEXTURES                                     512
#define MAX_GAME_OBJECTS                                4096


////////////////////////////////////////////////////////////////////////
// BASIC TYPES
////////////////////////////////////////////////////////////////////////

typedef char int8;
typedef short int int16;
typedef long int int32;
typedef long long int int64;

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

typedef float real32;
typedef double real64;


////////////////////////////////////////////////////////////////////////
// TIME
////////////////////////////////////////////////////////////////////////

class Time
{
public:
	static Time self;

	double time = 0.0f;     // Time in seconds since the application started
	float deltaTime = 0.0f; // Fixed update time step (use this for calculations)
	float frameTime = 0.0f; // Time spend during the last frame (don't use this)
};


////////////////////////////////////////////////////////////////////////
// LOG
////////////////////////////////////////////////////////////////////////

// Use log just like standard printf function.
// Example: LOG("New user connected %s\n", usernameString);

enum { LOG_TYPE_INFO, LOG_TYPE_WARN, LOG_TYPE_ERROR, LOG_TYPE_DEBUG };

#define LOG( m )  std::cout << __FILE__ << " -> line " << __LINE__ << " - " << LOG_TYPE_INFO << " - " << m << '\n'
#define WLOG( m ) std::cout << __FILE__ << " -> line " << __LINE__ << " - " << LOG_TYPE_WARN << " - " << m << '\n'
#define ELOG( m ) std::cout << __FILE__ << " -> line " << __LINE__ << " - " << LOG_TYPE_ERROR << " - " << m << '\n'
#define DLOG( m ) std::cout << __FILE__ << " -> line " << __LINE__ << " - " << LOG_TYPE_DEBUG << " - " << m << '\n'

