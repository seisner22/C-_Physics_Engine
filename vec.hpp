#include <math.h>

/**
 * @class vec3
 * @brief A class for 3D vectors
 *
 * This class implements some basic vector operations,
 * and some convenient constructors
*/
class vec3 {
 
  public:
	  float x, y, z;
  vec3() : x(0), y(0), z(0) {}
  vec3(float in_x, float in_y, float in_z) : x(in_x), y(in_y), z(in_z) {}
  vec3(const vec3 &in) : x(in.x), y(in.y), z(in.z) {}

  vec3 AddVec3(const vec3 a, const vec3 b) const {
    vec3 c;

    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;

    return c;
  };

  vec3 MultVec3(const vec3 a, const vec3 b) const {

    vec3 c;

    c.x = a.x * b.x;
    c.y = a.y * b.y;
    c.z = a.z * b.z;

    return c;
  };

  float length() const {
    return sqrt(x*x+y*y+z*z);
  }

  vec3& operator =( const vec3& rhs ) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
  }

  vec3 operator +( const vec3& rhs ) const {
    return AddVec3( *this, rhs );
  }

  vec3& operator +=( const vec3& rhs ) {
    *this = *this + rhs;
    return *this;
  }

  vec3 operator *( const vec3& rhs ) const {
    return MultVec3( *this, rhs );
  }

  vec3 operator *(float rhs) const {
    vec3 scale(rhs,rhs,rhs);
    return scale * (*this);
  }

  bool operator ==( const vec3& rhs) const {
    return x == rhs.x && y == rhs.y && z == rhs.z;
  }

	vec3 operator -( const vec3& rhs ) const {
		return vec3( x - rhs.x, y - rhs.y, z - rhs.z );
	}

	/**
	* @brief Check if any components are negative
	*/
	bool negative() const {
		return x<0 || y<0 || z<0;
	}
};

const vec3 operator*( float lhs, const vec3& rhs) {
  return rhs * lhs;
}

struct vec4 {
    struct vec3;
    float mass;
};
