// Asteroids game


#include "headers.h"
#include "gpuProgram.h"
#include "world.h"
#include "main.h"


GPUProgram *myGPUProgram;	// pointer to GPU program object

World *world;			// the world, including ship, asteroids, other ships, missiles

KeyState upKey    = UP;		// state of the arrow keys
KeyState downKey  = UP;
KeyState leftKey  = UP;
KeyState rightKey = UP;


// Handle a keypress and record the state (UP or DOWN) of the arrows


void keyCallback( GLFWwindow* window, int key, int scancode, int action, int mods )

{
  // Note that GLFW always returns the uppercase letter, even if the lowercase letter was pressed.
  
  if (action == GLFW_PRESS)
    
    switch (key) {
      
    case GLFW_KEY_ESCAPE:	// quit upon ESC
      glfwSetWindowShouldClose( window, GL_TRUE );
      break;
      
    case 'S':
      world->start(); break;
	
    case 'P':
      world->togglePause();break;

    case ' ':
      world->shipFires(); break;

    case GLFW_KEY_UP:
      upKey = DOWN; break;
      
    case GLFW_KEY_DOWN:
      downKey = DOWN; break;
      
    case GLFW_KEY_LEFT:
      leftKey = DOWN; break;
      
    case GLFW_KEY_RIGHT:
      rightKey = DOWN; break;
    }
      
  else if (action == GLFW_RELEASE)

    switch (key) {
      
    case GLFW_KEY_UP:
      upKey = UP; break;
      
    case GLFW_KEY_DOWN:
      downKey = UP; break;
      
    case GLFW_KEY_LEFT:
      leftKey = UP; break;
      
    case GLFW_KEY_RIGHT:
      rightKey = UP; break;
    }
}


  
// Error callback

void errorCallback( int error, const char* description )

{
  cerr << "Error " << error << ": " << description << endl;
  exit(1);
}



// Main program


int main( int argc, char **argv )

{
  // Trap all errors (do this *before* creating the window)

  glfwSetErrorCallback( errorCallback );
  
  // Init everything

  GLFWwindow* window;

  if (!glfwInit())
    return 1;
  
  glfwWindowHint( GLFW_CLIENT_API, GLFW_OPENGL_ES_API );
  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 0 );

  window = glfwCreateWindow( SCREEN_ASPECT * SCREEN_WIDTH, SCREEN_WIDTH, "Asteroids", NULL, NULL);
  
  if (!window) {
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent( window );
  glfwSwapInterval( 1 );
  gladLoadGLLoader( (GLADloadproc) glfwGetProcAddress );

  // Define callbacks

  glfwSetKeyCallback( window, keyCallback );

  // Set up vertex and fragment shaders

  myGPUProgram = new GPUProgram( "asteroids.vert", "asteroids.frag" );
  myGPUProgram->activate();

  // Seed the random number generator

  timeb time;
  ftime( &time );
  srand( time.time );

  // Set up world

  world = new World( WORLD_MIN, WORLD_MAX );

  // Main loop

  struct timeb prevTime, thisTime; // record the last rendering time
  ftime( &prevTime );

  while (!glfwWindowShouldClose( window )) {

    // Find elapsed time since last render

    ftime( &thisTime );
    float elapsedSeconds = (thisTime.time + thisTime.millitm / 1000.0) - (prevTime.time + prevTime.millitm / 1000.0);
    prevTime = thisTime;

    // Update the world state

    world->updateState( elapsedSeconds );

    // Clear, display, and check for events

    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glClear( GL_COLOR_BUFFER_BIT );
    
    world->draw();
      
    glfwSwapBuffers( window );
    glfwPollEvents();
  }

  // Clean up

  glfwDestroyWindow( window );
  glfwTerminate();

  return 0;
}
