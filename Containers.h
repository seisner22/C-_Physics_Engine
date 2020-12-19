#pragma once

#include <vector>
#include <cstdarg>

struct vec3 {
	float x, y, z;
};

vec3 AddVec3(vec3 a, vec3 b) {

	vec3 c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;

	return c;
};

vec3 MultVec3(vec3 a, vec3 b) {

	vec3 c;

	c.x = a.x * b.x;
	c.y = a.y * b.y;
	c.z = a.z * b.z;

	return c;
};


class PhysForce {
public:
	vec3 ForceVec;
	//void eval(...); I want to set this up so that each member of the PhysForce class can have it's own unique eval function
	//which contains the force. Wasn't quite sure how to do it so I tried using a variadic function that isn't declared for the class
	PhysForce() {
		ForceVec.x = 0.0;
		ForceVec.y = 0.0;
		ForceVec.z = 0.0;
	}

	void setForceVec(vec3 Force) {
		ForceVec = Force;
	}

};


class PhysObject {
public:
	//ColliderGeom Collide_Geom; We should have a colliderGeom class that we can pass to object classes and use in the update

	float mass;

	float Elasticity;

	float charge;

	float dt; //It seemed pointless for each new object to have it's own dt so I figured we have a universal dt and each object has its pointer

	vec3 ForceSum;

	vec3 CoM;

	vec3 CoM_momentum;

	std::vector<PhysForce> ForceList;

	PhysObject(){
		mass = 0;
		charge = 0;
		Elasticity = 1.0;
		ForceSum.x = 0.0f;
		ForceSum.y = 0.0f;
		ForceSum.z = 0.0f;
		//the CoM computation should go here and will use the ColliderGeom object with the mass to compute the CoM
	}

	void setMass(float m) {
		mass = m;
	}

	void setElasticity(float e) {
		Elasticity = e;
	}

	void setCharge(float q) {
		charge = q;
	}

	void setDt(float dT) {
		dt = dT;
	}

	void setCoM(vec3 com) {
		CoM = com;
	}

	void setCoM_momentum(vec3 com_mom) {
		CoM_momentum = com_mom;
	}

	void addForce(PhysForce force) {
		ForceList.push_back(force);
		ForceSum.x = ForceSum.x + force.ForceVec.x;
		ForceSum.y = ForceSum.y + force.ForceVec.y;
		ForceSum.z = ForceSum.z + force.ForceVec.z;
	}

	void update() {

		CoM_momentum.x = CoM_momentum.x + (dt) * ForceSum.x;
		CoM_momentum.y = CoM_momentum.y + (dt) * ForceSum.y;
		CoM_momentum.z = CoM_momentum.z + (dt) * ForceSum.z;

		CoM.x = CoM.x + (dt) * (1 / mass) * CoM_momentum.x;
		CoM.y = CoM.y + (dt) * (1 / mass) * CoM_momentum.y;
		CoM.z = CoM.z + (dt) * (1 / mass) * CoM_momentum.z;

		//So far this only updates CoM but depending upon how we set up the rigid body stuff, I can add a method for rigid body updates
	}


};

class PhysBound {
	public:
		std::vector<vec3> VertexList;
		float Elasticity;

		void addVertex(vec3 vertex){
			VertexList.push_back(vertex);
		}

		void setElasticity(float e) {
			Elasticity = e;
		}

		PhysBound() {
			Elasticity = 1.0;
		}

};

class PhysEnv {
	public:

		std::vector<PhysObject*> ObjectList;
		std::vector<PhysForce*> FieldList;
		std::vector<PhysBound*> BoundaryList;

		float dt;

		float time;

		PhysEnv() {
			dt = 0.01;
			time = 0.0;
		}

		void setDt(float dT) {
			dt = dT;
		}

		void setTime(float t) {
			time = t;
		}


		PhysObject CreateObject(float m, float q, float e, vec3 CoM, vec3 CoM_mom){
			
			PhysObject object;

			object.setMass(m);
			object.setCharge(q);
			object.setElasticity(e);
			object.setCoM(CoM);
			object.setCoM_momentum(CoM_mom);
			object.setDt(dt);

			ObjectList.push_back(&object);

			return object;
		
		}

		PhysBound CreateBound(float e, std::vector<vec3> Vertices) {
			PhysBound bound;

			bound.setElasticity(e);

			bound.VertexList = Vertices;

			BoundaryList.push_back(&bound);

			return bound;
		}

		PhysForce CreateUniformField(vec3 FieldVal) {
			PhysForce Field;

			Field.setForceVec(FieldVal);

			FieldList.push_back(&Field);

			for (int i = 0; i < (int)ObjectList.size(); i++) {
				//ObjectList[0]->addForce(Field);
			}

			return Field;

		}

		void update() {
			for (int i = 0; i < (int)ObjectList.size(); i++) {
				//ObjectList[i]->update();
			}

			time = time + dt;
		}


};
