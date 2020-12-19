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
