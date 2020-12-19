#pragma once

#include <vector>
#include <cstdarg>

class vec3 {
 
  public:
	  float x, y, z;
  vec3() : x(0), y(0), z(0) {}
  vec3(float in_x, float in_y, float in_z) : x(in_x), y(in_y), z(in_z) {}
  vec3(const vec3 &in) : x(in.x), y(in.y), z(in.z) {}
  vec3 AddVec3(const vec3 a, const vec3 b) const {
    vec3 c;

    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;

    return c;
  };

  vec3 MultVec3(const vec3 a, const vec3 b) const {

    vec3 c;

    c.x = a.x * b.x;
    c.y = a.y * b.y;
    c.z = a.z * b.z;

    return c;
  };

  vec3& operator =( const vec3& rhs ) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
  }

  vec3 operator +( const vec3& rhs ) const {
    return AddVec3( *this, rhs );
  }

  vec3& operator +=( const vec3& rhs ) {
    *this = *this + rhs;
    return *this;
  }

  vec3 operator *( const vec3& rhs ) const {
    return MultVec3( *this, rhs );
  }

  vec3 operator *(float rhs) const {
    vec3 scale(rhs,rhs,rhs);
    return scale * (*this);
  }

};

const vec3 operator*( float lhs, const vec3& rhs) {
  return rhs * lhs;
}

class PhysForce {
public:
	vec3 ForceVec;

	PhysForce() {
	}

	void setForceVec(vec3 Force) {
		ForceVec = Force;
	}

};

class triangle { // basic triangle class
public:
	vec3 a;
	vec3 b;
	vec3 c;
};

class sphere { //placeholder for sphere class

};

struct node //Placeholder for a binary tree structure
{
	sphere bound_sphere;
	node* left;
	node* right;
};


class PhysObject {
public:
	//ColliderGeom Collide_Geom; We should have a colliderGeom class that we can pass to object classes and use in the update

	float mass;

	float Elasticity;

	float charge;

	float dt;

	vec3 ForceSum;

	vec3 CoM;

	vec3 CoM_momentum;

	std::vector<triangle> TriangleList;

	std::vector<node> BoundingHierarchy;

	PhysObject(){
		mass = 0;
		charge = 0;
		Elasticity = 1.0;
		//the CoM computation should go here and will use the ColliderGeom object with the mass to compute the CoM

		//Things that need to be added here:
		//1. compute CoM from vertices
		//2. triangulate surface and update TriangleList
		//3. compute bounding sphere hierarchy from triangulation and update BoundingHierarchy

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

		std::vector<PhysObject> ObjectList = {};
		std::vector<PhysForce> FieldList = {};
		std::vector<PhysBound> BoundaryList = {};

		float dt;

		float time;

		PhysEnv() {
			dt = 0.01;
			time = 0.0;
		}

		PhysEnv(float dT = 0.01, float t = 0.0, int object_num = 0, float mass[] = {}, float charge[] = {}, float elasticity[] = {}, vec3 coms[] = {},
			vec3 coms_mom[] = {}, int boundary_num = 0, std::vector<vec3> bound_vertices[] = {}, float bound_elasticity[] = {}, int Field_num = 0, vec3 fields[] = {}) {
			dt = dT;
			time = t;

			for (int i = 0; i < object_num; i++) {
				CreateObject(mass[i], charge[i], elasticity[i], coms[i], coms_mom[i]);
			}

			for (int i = 0; i < boundary_num; i++) {
				CreateBound(bound_elasticity[i], bound_vertices[i]);
			}

			for (int i = 0; i < Field_num; i++) {
				CreateUniformField(fields[i]);
			}
		}

		PhysEnv(const PhysEnv &in): ObjectList(in.ObjectList), FieldList(in.FieldList), BoundaryList(in.BoundaryList), dt(in.dt), time(in.time) {}

		void setDt(float dT) {
			dt = dT;
		}

		void setTime(float t) {
			time = t;
		}


		void CreateObject(float m, float q, float e, vec3 CoM, vec3 CoM_mom){
			
			PhysObject object;

			object.setMass(m);
			object.setCharge(q);
			object.setElasticity(e);
			object.setCoM(CoM);
			object.setCoM_momentum(CoM_mom);
			object.setDt(dt);

			ObjectList.push_back(object);
		
		}

		void CreateBound(float e, std::vector<vec3> Vertices) {
			PhysBound bound;

			bound.setElasticity(e);

			bound.VertexList = Vertices;

			BoundaryList.push_back(bound);

		}

		void CreateUniformField(vec3 FieldVal) {
			PhysForce Field;

			Field.setForceVec(FieldVal);

			FieldList.push_back(Field);


		}

		void update() {
			vec3 dCoM;
			vec3 dCoM_Mom;
			vec3 CoM;
			vec3 CoM_Mom;
			PhysObject object;
			vec3 zeroes(0.0, 0.0, 0.0);

			for (int i = 0; i < ObjectList.size(); i++) {
				dCoM = zeroes;
				dCoM_Mom = zeroes;

				for (int j = 0; j < FieldList.size(); j++) {
					dCoM_Mom += FieldList[i].ForceVec;
				}

				//Add collision forces here

				object = ObjectList[i];

				CoM = object.CoM;

				CoM_Mom = object.CoM_momentum;

				CoM_Mom += dt * (dCoM_Mom);

				dCoM += (1 / (object.mass)) * CoM_Mom;

				CoM += dt * (dCoM);

				ObjectList[i].setCoM(CoM);

				ObjectList[i].setCoM_momentum(CoM_Mom);

				//Things that need to go here:
				//1. perform collision detection and return colliding object
				//2. use conservation of momentum to update CoM
				//3. use rigid body dynamics (torque, etc.) to update rotation coords


			}

			time = time + dt;
		}


};
