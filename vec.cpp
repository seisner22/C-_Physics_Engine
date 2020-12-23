#include "vec.hpp"

/*
 * @brief Checks two floats to see if they are almost equal
 */
bool feq(float a, float b, float e = std::numeric_limits<float>::epsilon()) {
	return std::fabs(a-b) <= e;
}

vec3 vec3::AddVec3(const vec3 a, const vec3 b) const {
	vec3 c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;

	return c;
};

vec3 vec3::entrywise_product(const vec3& a, const vec3& b) const {
	return vec3(a.x * b.x, a.y * b.y, a.z * b.z);
};

vec3 vec3::entrywise_product( const vec3& b) const {
	return entrywise_product(*this, b);
};

float vec3::dot_product(const vec3& a, const vec3& b) const {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

float vec3::dot_product(const vec3& b) const {
	return dot_product(*this, b);
}

vec3 vec3::cross_product(const vec3& a, const vec3& b) const {
	return vec3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

vec3 vec3::cross_product(const vec3& b) const {
	return cross_product(*this, b);
}

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

vec3 vec3::operator *(float rhs) const {
	return entrywise_product(vec3(rhs,rhs,rhs));
}

bool vec3::operator ==( const vec3& rhs) const {
	return feq(x,rhs.x) && feq(y,rhs.y) && feq(z,rhs.z);
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

std::ostream& operator<<(std::ostream &out, const vec3& rhs) {
	out << "(" << rhs.x << "," << rhs.y << "," << rhs.z << ")";
	return out;
}
