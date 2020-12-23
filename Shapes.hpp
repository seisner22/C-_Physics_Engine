#pragma once
#include "vec.hpp"
#include <vector>

class Box;
class Sphere;

class Collider {
  public:
    virtual bool contains(const vec3& in) const = 0;
    virtual vec3 findCenter() const = 0;
    virtual Box getBoundingBox() const = 0;
    virtual Sphere getBoundingSphere() const = 0;
};

class Triangle : public Collider {
	public:
		std::vector<vec3> points = {};

    bool contains(const vec3& in) const;
		vec3 findCenter() const;
		Box getBoundingBox() const;
		Sphere getBoundingSphere() const;
};

class Box : public Collider {
	private:
		vec3 center;
		std::vector<vec3> points;
	public:
		Box(const Box &in) : center(in.center), points(in.points) {}
		Box(vec3 center_in, vec3 a, vec3 b) : center(center_in), points{a,b} { }
		Box(vec3 center_in, float width, float length, float height) : center(center_in), points{vec3(width/2, length/2, height/2), vec3(-width/2,-length/2, - height/2)} {}

		bool operator== (const Box& rhs) const;
		friend std::ostream& operator<<(std::ostream &out, const Box& rhs);

		bool contains(const vec3& in) const;
		vec3 findCenter() const;
		Box getBoundingBox() const;
		Sphere getBoundingSphere() const;
};

class Sphere : public Collider {
		private:
        float radius;
        vec3 center;
        
    public:
				Sphere(const vec3& c, float r) : radius{r}, center{c} {}
				bool operator== (const Sphere& rhs) const;

        bool contains(const vec3& in) const;
				vec3 findCenter() const;
				Box getBoundingBox() const;
				Sphere getBoundingSphere() const;
};

class Prism : public Collider {
    public:
				vec3 center;
        std::vector<vec3> points;
        void addPoint(vec3 point);

				bool contains(const vec3& in) const;
				vec3 findCenter() const;
				Box getBoundingBox() const;
				Sphere getBoundingSphere() const;
};
