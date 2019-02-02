// The standard headers included by all files


#ifndef HEADERS_H
#define HEADERS_H

#include "glad/include/glad/glad.h"
#include "include/GLFW/glfw3.h"
//#include <GL/glu.h>

#ifdef _WIN32
  #include <windows.h>
  #include <typeinfo>
  #define M_PI 3.14159
  #define MAXFLOAT 9.9e10
  #pragma warning(disable : 4244 4305 4996)
#endif

#include <sys/timeb.h>	// includes ftime (to return current time)

#ifdef LINUX
  #include <unistd.h>		// includes usleep (to sleep for some time)
  #include <values.h>           // includes MAX_FLOAT
  #define sprintf_s sprintf
  #define _strdup strdup
  #define sscanf_s sscanf
#endif

#ifdef __APPLE_CC__
#endif

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

// This function is already defined in Windows.
// We redefine it here according to our desired behaviour

#ifdef _WIN32
  #define rint(x) floor((x)+0.5)
#endif

#include <math.h>

#include "linalg.h"

#define randIn01() (rand() / (float)RAND_MAX)   // random number in [0,1]

#endif
