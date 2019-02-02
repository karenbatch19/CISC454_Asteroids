// asteroid.h


#ifndef ASTEROID_H
#define ASTEROID_H


#include "headers.h"
#include "object.h"


#define ASTEROID_SPEED 30           // m/s
#define ASTEROID_ROTATION_SPEED 0.75 // radians/s
#define ASTEROID_MASS 5000	    // kg
#define ASTEROID_WIDTH 50	    // m

#define NUM_ASTEROID_MODELS 4

#define FRAGMENT_MAX_TIME 0.5	// s; added


class Asteroid : public Object {

  static float *asteroidModels[];

 public:

  float scoreValue;
	float elapsedTime;		// added
	bool isFragment;		// added

  Asteroid( vec3 position )
    : Object( position,
	      asteroidModels[ (int) floor( randIn01() * NUM_ASTEROID_MODELS ) ],
	      ASTEROID_WIDTH,
	      ASTEROID_MASS ) {

    scoreValue = 100;
    float theta = randIn01() * 2 * M_PI;
    orientation = quaternion( theta, vec3(0,0,1) );
    velocity = ASTEROID_SPEED * (orientation * vec3(0,1,0));
    angularVelocity = ASTEROID_ROTATION_SPEED * vec3(0,0,1);
    mass = ASTEROID_MASS;
		elapsedTime = 0;		// added
		isFragment = false;		// added
  };
};


#endif
