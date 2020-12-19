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

};

const vec3 operator*( float lhs, const vec3& rhs) {
  return rhs * lhs;
}

struct vec3 {
    float x, y, z;
};

struct vec4 {
    struct vec3;
    float mass;
};

vec3 add(vec3 one, vec3 two) {
    return {one.x+two.x, one.y+two.y, one.z+two.z};
}

vec3 mult(vec3 one, vec3 two) {
    return {one.x*two.x, one.y*two.y, one.z*two.z};
}

float dotProd(vec3 one, vec3 two) {
    return one.x*two.x + one.y*two.y + one.z*two.z;
}
