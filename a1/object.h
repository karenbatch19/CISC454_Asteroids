// object.h
//
// A 2D object represented with a set of line segments, having
// position, velocity, mass


#ifndef OBJECT_H
#define OBJECT_H


#include "headers.h"
#include "segment.h"
#include <vector> 


class Object {

 public:

  GLuint VAO;			// VAO for geometry
  vector<Segment> segments;	// all segments of model

	int numSegments;	// number of line segments in the object model; **added

  vec3  position;		// position in world coordinates (m)
  vec3  velocity;		// velocity in world coordinates (m/s)
  float mass;			// (kg)

  quaternion orientation;
  vec3  angularVelocity;        // angular velocity (vector with length = radians/second CCW)

  float scaleFactor;

  // Object has an initial position, set of edges (in verts), a width,
  // and a mass.

  Object( vec3 position, float verts[], float width, float mass ) {
    setupVAO( verts, width );
    scaleFactor = 1;
    reset( position );
  };

  void setupVAO( float objectVerts[], float objectWidth );  
  void draw( mat4 &worldToViewTransform );
  void updatePose( float deltaT );
  mat4 modelToWorldTransform() const;
  bool intersects( Segment const& seg ) const;
  bool intersects( Object const& obj ) const;

  void reset( vec3 pos ) {
    position = pos;
    velocity = vec3(0,0,0);
    orientation = quaternion( 1, 0, 0, 0 ); // rotation of zero
    angularVelocity = vec3( 0, 0, 0 );
  }

  vec3 centrePosition() {
    return position;
  }
  
  float speed() {
    return velocity.length();
  }
};


#endif

