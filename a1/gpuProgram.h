// GPUProgram class

#ifndef SHADER_H
#define SHADER_H


#include "headers.h"


class GPUProgram {

  unsigned int program_id;
  unsigned int shader_vp;
  unsigned int shader_fp;

 public:

  GPUProgram() {};

  GPUProgram( const char *vsFile, const char *fsFile ) {
    initFromFile( vsFile, fsFile );
  }

  void initFromFile( const char *vsFile, const char *fsFile ) {
    
    char* vsText = textFileRead(vsFile);	
    
    if (vsText == NULL) {
      std::cerr << "Vertex shader file '" << vsFile << "' not found." << std::endl;
      return;
    }
    
    char* fsText = textFileRead(fsFile);
    
    if (fsText == NULL) {
      std::cerr << "Fragment shader file '" << fsFile << "' not found." << std::endl;
      return;
    }
    
    init( vsText, fsText );
  }

  ~GPUProgram() {
    glDetachShader( program_id, shader_vp );
    glDeleteShader( shader_vp );

    glDetachShader( program_id, shader_fp );
    glDeleteShader( shader_fp );

    glDeleteProgram( program_id );
  }

  void init( char *vsText, char *fsText );

  int id() {
    return program_id;
  }

  void activate() {
    glUseProgram( program_id );
  }

  void deactivate() {
    glUseProgram( 0 );
  }

  char* textFileRead(const char *fileName);


  void glErrorReport( char *where ) {

    GLuint errnum;

    while ((errnum = glGetError()) != GL_NO_ERROR) {
      char *errstr;
      switch (errnum) {
      case GL_INVALID_ENUM:
	errstr = "Invalid enumeration parameter";
	break;
      case GL_INVALID_VALUE:
	errstr = "Invalid value parameter";
	break;
      case GL_INVALID_OPERATION:
	errstr = "Invalid operation";
	break;
      case GL_STACK_OVERFLOW:
	errstr = "Stack overflow";
	break;
      case GL_STACK_UNDERFLOW:
	errstr = "Stack underflow";
	break;
      case GL_OUT_OF_MEMORY:
	errstr = "Out of memory";
	break;
      case GL_INVALID_FRAMEBUFFER_OPERATION:
	errstr = "Invalid framebuffer operation";
	break;
      default:
	errstr = "Unknown error";
      }
      std::cerr << where << ": " << errstr << std::endl;
    }
  }

};

#endif
