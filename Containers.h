#pragma once

#include <vector>
#include <cstdarg>

class vec3 {
  private:
	  float x, y, z;

  public:
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
	//void eval(...); I want to set this up so that each member of the PhysForce class can have it's own unique eval function
	//which contains the force. Wasn't quite sure how to do it so I tried using a variadic function that isn't declared for the class
	PhysForce() {
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
    ForceSum += force.ForceVec;
	}

	void update() {

    CoM_momentum += dt * ForceSum;
    CoM += dt * (1/mass) * CoM_momentum;

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
