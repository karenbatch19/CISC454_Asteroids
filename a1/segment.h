// segment.h


class Segment {
 public:

  vec3 tail, head;

  Segment( vec3 t, vec3 h )
    { tail = t; head = h; }

  bool intersects( Segment const& s2 ) {

    // YOUR CODE HERE
		// ** Question 5 ** //

		vec3 a = head;
		vec3 b = tail;
		vec3 c = s2.head;
		vec3 d = s2.tail;

		float denom = ((b.x - a.x) * (d.y - c.y)) - ((b.y - a.y) * (d.x - c.x));
		float nume1 = ((a.y - c.y) * (d.x - c.x)) - ((a.x - c.x) * (d.y - c.y));
		float nume2 = ((a.y - c.y) * (b.x - a.x)) - ((a.x - c.x) * (b.y - a.y));

		float r = nume1 / denom;
		float s = nume2 / denom;

		return (r >= 0 && r <= 1) && (s >= 0 && s <= 1);

		// Found code on StackExchange to detect the intersection of two line segments
		// Originally written by: David Gouveia
		// https://gamedev.stackexchange.com/questions/26004/how-to-detect-2d-line-on-line-collision?fbclid=IwAR2ZhS7YA_-caVqgWGNT8nmqwY-NFtGe32LDok4BszQn9_CS4FI5U-cuBU8

  }
};


