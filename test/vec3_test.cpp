#include "vec.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE vec3
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(vec3_equality) {
  vec3 a(1,1,1);
  vec3 b(1,1,1);
  BOOST_REQUIRE(a == b);

	vec3 c(2.4,2.5,2.6);
	vec3 d(2.4,2.5,2.6);
  BOOST_REQUIRE(c == d);
}

BOOST_AUTO_TEST_CASE(vec3_add) {
  vec3 a(1,1,1);
  vec3 b(2,2,2);
  vec3 c;
  c = a.AddVec3(a,b);
  BOOST_CHECK(c == vec3(3,3,3));
}

BOOST_AUTO_TEST_CASE(vec3_add_operator) {
  vec3 a(1,1,1);
  vec3 b(2,2,2);
  vec3 c;
  c = a+b;
  BOOST_CHECK(c == vec3(3,3,3));
}

BOOST_AUTO_TEST_CASE(vec3_add_assign) {
  vec3 a(1,1,1);
  vec3 b(2,2,2);
  a+=b;
  BOOST_CHECK(a == vec3(3,3,3));
}

BOOST_AUTO_TEST_CASE(vec3_length) {
	vec3 a(2,3,6);
	BOOST_REQUIRE(a.length() == 7);
}

BOOST_AUTO_TEST_CASE(vec3_subtract) {
	vec3 a(4,5,6);
	vec3 b(1,3,5);
	vec3 c(3,2,1);
	vec3 d = a - b;
	BOOST_REQUIRE(c == d);
}

BOOST_AUTO_TEST_CASE(vec3_multiply) {
	vec3 a(2,3,5);
	vec3 b(7,9,11);
	vec3 c(14,27,55);
	vec3 d;
	d = a.entrywise_product(a,b);
	BOOST_REQUIRE(c == d);
}

BOOST_AUTO_TEST_CASE(vec3_multiply_operator) {
	vec3 a(2,3,5);
	vec3 b(7,9,11);
	vec3 c(14,27,55);
	vec3 d;
	d = a.entrywise_product(b);
	BOOST_REQUIRE(c == d);
}

BOOST_AUTO_TEST_CASE(vec3_multiply_scalar) {
	vec3 a(2,3,5);
	vec3 b;
	b = a*7;
	vec3 d(14, 21, 35);
	BOOST_REQUIRE(b == d);
}


BOOST_AUTO_TEST_CASE(vec3_max_components) {
	vec3 a(2,5,7);
	vec3 b(9,2,11);
	vec3 c;
	c = a.max_components(b);
	BOOST_REQUIRE(c == vec3(9,5,11));
}

BOOST_AUTO_TEST_CASE(vec3_min_components) {
	vec3 a(2,5,7);
	vec3 b(9,2,11);
	vec3 c;
	c = a.min_components(b);
	BOOST_REQUIRE(c == vec3(2,2,7));
}

BOOST_AUTO_TEST_CASE(vec3_negative) {
	vec3 a(-2,3,-11);
	bool b = a.negative();
	BOOST_REQUIRE(b == true);
}

BOOST_AUTO_TEST_CASE(vec3_multiply_scalar_lhs) {
	vec3 a(2,3,5);
	float f = 0.5;
	vec3 b;
	b = f*a;
	BOOST_REQUIRE(b == vec3(1,1.5,2.5));
}
