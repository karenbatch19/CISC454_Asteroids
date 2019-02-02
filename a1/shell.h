// shell.h


#ifndef SHELL_H
#define SHELL_H


#include "headers.h"
#include "object.h"


#define SHELL_WIDTH 0.4
#define SHELL_MASS 5
#define SHELL_SPEED 200
#define SHELL_MAX_TIME  2


class Shell : public Object {

  static float verts[];

 public:

  float elapsedTime;

 Shell( vec3 position, vec3 vel, quaternion orient )
    : Object( position, verts, SHELL_WIDTH, SHELL_MASS ) {

    orientation = orient;
    velocity = vel;
    elapsedTime = 0;
  };

  
};


#endif
