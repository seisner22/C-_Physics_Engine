#include "Containers.hpp"
#include <iostream>
#include <cstdio>
#include <vector>
#include <typeinfo>

int main() {

	PhysEnv env1(0.01, 0.0) ;

	vec3 com(0, 0, 10.0);

	vec3 com_mom;

	vec3 g(0,0,-9.81);

	env1.setDt(0.1);

	float maxTime = 1.0;

	env1.CreateObject(1.0, 0.0, 1.0, com, com_mom);

	env1.CreateUniformField(g); 

	std::cout << env1.FieldList.size() << "\n";

	while (env1.time < maxTime) {
		env1.update();
		std::cout << env1.time << "\n";
		std::cout << (env1.ObjectList[0]).CoM.z << "\n";
	}

	std::cout << "Success" << "\n";

}
