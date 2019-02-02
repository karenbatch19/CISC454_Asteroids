// ship.h


#ifndef SHIP_H
#define SHIP_H


#include <vector>
#include "headers.h"
#include "object.h"
#include "shell.h"


#define SHIP_ROTATION_SPEED 2.5  // upon sidewise thrust, rotation speed in radians/second
#define SHIP_THRUST_ACCEL 50.0   // upon main thrust, acceleration in m/s/s
#define SHIP_WIDTH 10		 // ship is 10 m wide
#define SHIP_MASS 5000		 // ship is 5000 kg


class Ship : public Object {

  static float verts[];

 public:

  Ship( vec3 position )
    : Object( position, verts, SHIP_WIDTH, SHIP_MASS )
    {};

  void rotateCW( float deltaT );
  void rotateCCW( float deltaT );
  void addThrust( float deltaT );
  Shell *fireShell();
};


#endif
