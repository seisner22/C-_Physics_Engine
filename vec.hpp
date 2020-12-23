#pragma once
#include <math.h>

/**
 * @class vec3
 * @brief A class for 3D vectors
 *
 * This class implements some basic vector operations,
 * and some convenient constructors
*/
class vec3 {
	private:

	public:
	float x, y, z;
	vec3() : x(0), y(0), z(0) {}
	vec3(float in_x, float in_y, float in_z) : x(in_x), y(in_y), z(in_z) {}
	vec3(const vec3 &in) : x(in.x), y(in.y), z(in.z) {}
	vec3 AddVec3(const vec3 a, const vec3 b) const;
	float length() const;
	vec3& operator =( const vec3& rhs );
	vec3 operator +( const vec3& rhs ) const;
	vec3& operator +=( const vec3& rhs );
	bool operator ==( const vec3& rhs) const;
	vec3 operator -( const vec3& rhs ) const;
	bool negative() const;
	vec3 max_components( const vec3& rhs ) const;
	vec3 min_components( const vec3& rhs ) const;
	vec3 entrywise_product(const vec3& a, const vec3& b) const;
	float dot_product(const vec3& a, const vec3& b) const;
	vec3 cross_product(const vec3& a, const vec3& b) const;
	vec3 entrywise_product(const vec3& b) const;
	float dot_product(const vec3& b) const;
	vec3 cross_product(const vec3& b) const;
	vec3 operator *(float rhs) const;
	friend const vec3 operator*( float lhs, const vec3& rhs);
};

struct vec4 {
    struct vec3;
    float mass;
};
