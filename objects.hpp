#include <vector>
#include "vec.hpp"

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
