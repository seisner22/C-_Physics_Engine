#include "Shapes.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE vec3
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(Triangle_findCenter) {
	Triangle a;
	a.points.push_back(vec3(1,1,1));
	a.points.push_back(vec3(5,1,1));
	a.points.push_back(vec3(3,4,4));
	BOOST_REQUIRE(a.findCenter() == vec3(3,2,2));
}

BOOST_AUTO_TEST_CASE(Triangle_contains) {
	Triangle a;
	a.points.push_back(vec3(1,1,1));
	a.points.push_back(vec3(5,1,1));
	a.points.push_back(vec3(3,4,4));
	//BOOST_CHECK(a.contains(vec3(2,2,2)));
	BOOST_TEST_MESSAGE( "Fix Triangle::contains method" );
}

BOOST_AUTO_TEST_CASE(Triangle_getBoundingBox) {
	Triangle a;
	a.points.push_back(vec3(1,1,1));
	a.points.push_back(vec3(5,1,1));
	a.points.push_back(vec3(3,4,4));
  Box b(vec3(3,2.5,2.5),vec3(-2,-1.5,-1.5),vec3(2,1.5,1.5));

  BOOST_CHECK(a.getBoundingBox() == b);
}

BOOST_AUTO_TEST_CASE(Triangle_getBoundingSphere) {
	Triangle a;
	a.points.push_back(vec3(1,1,1));
	a.points.push_back(vec3(5,1,1));
	a.points.push_back(vec3(3,4,4));
	Sphere b(vec3(3,2.5,2.5),vec3(2,1.5,1.5).length());

	BOOST_CHECK(a.getBoundingSphere() == b);
}

BOOST_AUTO_TEST_CASE(Box_contains_point) {
	Box a(vec3(1,1,1), vec3(-1,-1,-1), vec3(1,1,1));
	BOOST_REQUIRE(a.contains(vec3(0.5,0.5,0.5)));
}

BOOST_AUTO_TEST_CASE(Box_findCenter) {
	BOOST_FAIL("Test Box_findCenter is not ready");
}

BOOST_AUTO_TEST_CASE(Box_getBoundingBox) {
	BOOST_FAIL("Test Box_getBoundingBox is not ready");
}

BOOST_AUTO_TEST_CASE(Box_getBoundingSphere) {
	BOOST_FAIL("Test Box_getBoundingSphere is not ready");
}

BOOST_AUTO_TEST_CASE(Sphere_contains) {
	BOOST_FAIL("Test Sphere_contains is not ready");
}

BOOST_AUTO_TEST_CASE(Sphere_findCenter) {
	BOOST_FAIL("Test Sphere_findCenter is not ready");
}

BOOST_AUTO_TEST_CASE(Sphere_getBoundingBox) {
	BOOST_FAIL("Test Sphere_getBoundingBox is not ready");
}

BOOST_AUTO_TEST_CASE(Sphere_getBoundingSphere) {
	BOOST_FAIL("Test Sphere_getBoundingSphere is not ready");
}

BOOST_AUTO_TEST_CASE(Prism_contains) {
	BOOST_FAIL("Test Prism_contains is not ready");
}

BOOST_AUTO_TEST_CASE(Prism_findCenter) {
	BOOST_FAIL("Test Prism_findCenter is not ready");
}

BOOST_AUTO_TEST_CASE(Prism_getBoundingBox) {
	BOOST_FAIL("Test Prism_getBoundingBox is not ready");
}

BOOST_AUTO_TEST_CASE(Prism_getBoundingSphere) {
	BOOST_FAIL("Test Prism_getBoundingSphere is not ready");
}
