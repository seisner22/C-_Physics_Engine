#include "vec.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE vec3
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(vec3_equality) {
  vec3 a(1,1,1);
  vec3 b(1,1,1);
  BOOST_REQUIRE(a == b);
}

BOOST_AUTO_TEST_CASE(test_vec3) {
  vec3 a(1,1,1);
  vec3 b(2,2,2);
  vec3 c;
  c = a.AddVec3(a,b);
  BOOST_CHECK(c == vec3(3,3,3));
}
