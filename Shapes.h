#include "vec.hpp"
#include <vector>

class Triangle {
	public:
		std::vector<vec3> points = {};
		vec3 findCenter() {
			float ox = points.at(0).x + points.at(1).x + points.at(2).x;
			float oy = points.at(0).y + points.at(1).y + points.at(2).y;
			float oz = points.at(0).z + points.at(1).z + points.at(2).z;

			return {ox/3, oy/3, oz/3};
		}
};

class Sphere {
    public:
        float radius;
        vec3 center;
};

class Prism {
    public:
        std::vector<vec3> points;
        void addPoint(vec3 point) {
            points.push_back(point);
        }
};
