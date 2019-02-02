// main.h

#ifndef MAIN_H
#define MAIN_H


class GPUProgram;
extern GPUProgram *myGPUProgram;

class World;
extern World *world;

typedef enum { UP, DOWN } KeyState;
extern KeyState upKey, downKey, leftKey, rightKey, spaceBar;


#define SCREEN_WIDTH 800	// width in pixels
#define SCREEN_ASPECT 1.3333333	// 4:3 aspect ratio

extern void gameOver();

#endif
