#include "vec.hpp"
#include <vector>

class Collider {
  public:
    virtual bool contains(const vec3& in) const;
    virtual vec3 findCenter() const;
    virtual Collider getBoundingBox() const;
    virtual Collider getBoundingSphere() const;
};

class Triangle : public Collider {
	public:
		std::vector<vec3> points = {};
		vec3 findCenter() {
			float ox = points.at(0).x + points.at(1).x + points.at(2).x;
			float oy = points.at(0).y + points.at(1).y + points.at(2).y;
			float oz = points.at(0).z + points.at(1).z + points.at(2).z;

			return {ox/3, oy/3, oz/3};
		}

    bool contains(const vec3& in) {
			return false;
    }
};

class Sphere;
class Box : public Collider {
	private:
		vec3 center;
		std::vector<vec3> points;
	public:
		Box(const Box &in) : center(in.center), points(in.points) {}
		Box(vec3 center_in, vec3 a, vec3 b) : center(center_in), points{a,b} { }
		Box(vec3 center_in, float width, float length, float height) : center(center_in), points{vec3(width/2, length/2, height/2), vec3(-width/2,-length/2, - height/2)} {}

		/**
		 * @ brief Determines if a point is contained by the point
		 * We represent a box as 1. It's center, as a vector from the origin
		 * and 2. Two vectors to define opposite corners of the box, as defined
		 * from the box center.
		 * 
		 * To determine if a point is in the box, we first find the volume vector
		 * from the bottom left to the top right. Then we find the difference 
		 * vector of the point in reference to the bottom corner of the box.
     * Now that we have two vectors in reference to the same starting point,
		 * we can subtract the point from the volume vector, and if any of the
		 * parts are negative, we know the point is outside the box.
		*/
		bool contains(const vec3& in) const {
			vec3 corner = center + points[0];
			vec3 volume = 2*points[1];
			vec3 diff = in - corner;
			return (volume - diff).negative();
		}

		vec3 findCenter() {
			return center;
		}

		Collider getBoundingBox() const {
			return Box(*this);
		}

		Collider getBoundingSphere() const {
			return Sphere(center, points[0].length);
		}
};

class Sphere : public Collider {
		private:
        float radius;
        vec3 center;
        
    public:
				Sphere(const vec3& c, float r) : radius{r}, center{c} {}
        bool contains(const vec3& in) {
          vec3 d = center - in;
          return radius >= d.length();
        }

				Collider getBoundingSphere() const {
					return Sphere(radius, center);
				}
};

class Prism : public Collider {
    public:
        std::vector<vec3> points;
        void addPoint(vec3 point) {
            points.push_back(point);
        }

				bool contains(const vec3& in) {
					return false;
				}
};
