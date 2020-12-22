#include "vec.hpp"

vec3 vec3::AddVec3(const vec3 a, const vec3 b) const {
	vec3 c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;

	return c;
};

vec3 vec3::MultVec3(const vec3 a, const vec3 b) const {

	vec3 c;

	c.x = a.x * b.x;
	c.y = a.y * b.y;
	c.z = a.z * b.z;

	return c;
};

float vec3::length() const {
	return sqrt(x*x+y*y+z*z);
}

vec3& vec3::operator =( const vec3& rhs ) {
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

vec3 vec3::operator +( const vec3& rhs ) const {
	return AddVec3( *this, rhs );
}

vec3& vec3::operator +=( const vec3& rhs ) {
	*this = *this + rhs;
	return *this;
}

vec3 vec3::operator *( const vec3& rhs ) const {
	return MultVec3( *this, rhs );
}

vec3 vec3::operator *(float rhs) const {
	vec3 scale(rhs,rhs,rhs);
	return scale * (*this);
}

bool vec3::operator ==( const vec3& rhs) const {
	return x == rhs.x && y == rhs.y && z == rhs.z;
}

vec3 vec3::operator -( const vec3& rhs ) const {
	return vec3( x - rhs.x, y - rhs.y, z - rhs.z );
}

/**
 * Given a vector, return a vector consisting of the maximum components
 * between the two input vectors
 */
vec3 vec3::max_components(const vec3& rhs) const {
	vec3 r(*this);
	r.x = ( x>rhs.x ) ? x : rhs.x;
	r.y = ( y>rhs.y ) ? y : rhs.y;
	r.z = ( z>rhs.z ) ? z : rhs.z;
	return r;
}

/**
 * Given a vector, return a vector consisting of the minimum components
 * between the two input vectors
 */
vec3 vec3::min_components(const vec3& rhs) const {
	vec3 r(*this);
	r.x = ( x<rhs.x ) ? x : rhs.x;
	r.y = ( y<rhs.y ) ? y : rhs.y;
	r.z = ( z<rhs.z ) ? z : rhs.z;
	return r;
}

/**
* @brief Check if any components are negative
*/
bool vec3::negative() const {
	return x<0 || y<0 || z<0;
}

const vec3 operator*( float lhs, const vec3& rhs) {
  return rhs * lhs;
}
