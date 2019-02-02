// asteroids vertex shader

#version 300 es


layout (location = 0) in mediump vec4 position;
uniform mediump mat4 MVP;


void main()

{
  gl_Position = MVP * position;
}
