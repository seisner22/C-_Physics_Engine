#include <C:\Users\eisne\Documents\cpp source\Physics Engine\C-_Physics_Engine\Containers.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <typeinfo>

int main() {

	PhysEnv env1 ;

	vec3 com;

	com.x = 0.0;
	com.y = 0.0;
	com.z = 0.0;

	vec3 g;

	g.x = 0.0;
	g.y = 0.0;
	g.z = -9.81;

	env1.setDt(0.01);

	float maxTime = 1.0;

	PhysObject object1 = env1.CreateObject(1.0, 0.0, 1.0, com, com);

	PhysForce gravity = env1.CreateUniformField(g); //I'm having problems with this method, I can't get it to update the forces on each object

	while (env1.time < maxTime) {
		env1.update();
		std::cout << env1.time << "\n";
	}

	std::cout << "Success" << "\n";

}