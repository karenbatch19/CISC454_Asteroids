// world.h


#ifndef WORLD_H
#define WORLD_H


#include <vector>
#include "headers.h"
#include "ship.h"
#include "asteroid.h"
#include "main.h"
#include "seq.h"
#include "shell.h"


#define WORLD_MIN vec3( 0, 0, 0 )
#define WORLD_MAX vec3( SCREEN_WIDTH, SCREEN_WIDTH/SCREEN_ASPECT, 0 )

#define NUM_INITIAL_ASTEROIDS 10
#define ASTEROID_SCALE_FACTOR_REDUCTION 0.5  // factor by which size changes upon breakup
#define MIN_ASTEROID_SCALE_FACTOR 0.25       // min scale before asteroid is destroyed
#define ASTEROID_SPEED_INCREASE 2            // factor by which speed changes upon breakup
#define ASTEROID_SPEED_ROUND_FACTOR 0.5      // factor by which asteroid speed increases with each round

typedef enum { BEFORE_GAME, RUNNING, PAUSED, AFTER_GAME } State;

class World {

  Ship *ship;
  vector<Asteroid *> asteroids;
  vector<Shell *> shells;

  int score;
  int round;
  State state;			// game state

 public:

  vec3 worldMin, worldMax;	// min and max world coordinates

  World( vec3 min, vec3 max ) {
    worldMin = min;
    worldMax = max;
    start();
    state = BEFORE_GAME;
    score = 0;
    round = 0;
  }

  void start();
  void togglePause();
  void updateState( float elapsedTime );
  void draw();
  void gameOver();

  void shipFires() {
    if (state == RUNNING)
      shells.push_back( ship->fireShell() );
  }
};


#endif
