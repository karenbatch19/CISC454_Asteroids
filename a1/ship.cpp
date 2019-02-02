// ship.cpp


#include "ship.h"


void Ship::rotateCW( float deltaT )

{
  orientation = quaternion( - SHIP_ROTATION_SPEED * deltaT, vec3(0,0,1) ) * orientation;
}


void Ship::rotateCCW( float deltaT )

{
  orientation = quaternion( + SHIP_ROTATION_SPEED * deltaT, vec3(0,0,1) ) * orientation;
}


void Ship::addThrust( float deltaT )

{
  // Thrust is in the ship's +y direction.  Make sure to change the
  // velocity in that direction in the *world* coordinate system,
  // since the object velocity is in the world coordinate system.

  // YOUR CODE HERE
	// **	Question 4 ** //

	vec3 thrust = (orientation.toMatrix() * vec4(0, SHIP_THRUST_ACCEL * deltaT, 0, 1)).toVec3();

	velocity = velocity + thrust;

}


Shell * Ship::fireShell()

{
  // YOUR CODE HERE (below, find the correct position, velocity, and orientation for the shell)
	// ** Question 6 ** //

  return new Shell( position, SHELL_SPEED * (orientation.toMatrix() * vec3(0,1,0)).toVec3(), orientation );

}


// Ship model consisting of line segments
//
// These are in a ARBITRARY coordinate system and get remapped to the
// world coordinate system (with the centre of the ship at (0,0) and
// width SHIP_WIDTH) when the VAO is set up.


float Ship::verts[] = {

   3,0,  0,9,
   0,9, -3,0, 
  -3,0,  0,1,
   0,1,  3,0,

  9999
};

